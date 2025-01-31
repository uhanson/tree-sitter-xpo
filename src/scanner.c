#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"

enum TokenType {
    INDENT,
    DEDENT,
    NBSP,
    NEWLINE,
    WHITESPACE,
    ERROR_SENTINEL,
};

typedef struct {
    Array(uint32_t) indents;
    int row;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

bool tree_sitter_xpo_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    lexer->mark_end(lexer);

    if (false && valid_symbols[ERROR_SENTINEL]) {
        while (lexer->lookahead != '\n' && !lexer->eof(lexer))
            skip(lexer);
    }

    bool nbsp = true;
    bool white_space = false;
    bool found_end_of_line = false;
    uint32_t current_indent = lexer->get_column(lexer);
    for (;;) {
        if (lexer->lookahead == '\n') {
            found_end_of_line = true;
            white_space = true;
            scanner->row++;
            current_indent = 0;
            nbsp = false;
            skip(lexer);
        } else if (lexer->lookahead == ' ') {
            white_space = true;
            current_indent++;
            skip(lexer);
        } else if (lexer->lookahead == '\r' || lexer->lookahead == '\f') {
            white_space = true;
            nbsp = false;
            current_indent = 0;
            skip(lexer);
        } else if (lexer->lookahead == '\t') {
            white_space = true;
            current_indent += 8;
            skip(lexer);
        } else if (lexer->eof(lexer)) {
            found_end_of_line = true;
            break;
        } else {
            break;
        }
    }

    lexer->mark_end(lexer);

    uint32_t last_indent = scanner->indents.size > 0 ? *array_back(&scanner->indents) : 0;
    bool next_token_is_a_tag = lexer->lookahead != '*' && lexer->lookahead != ';';

    if (found_end_of_line) {
        if (valid_symbols[INDENT] && current_indent > last_indent) {
            array_push(&scanner->indents, current_indent);
            lexer->result_symbol = INDENT;
            return true;
        }

        if (valid_symbols[DEDENT] && scanner->indents.size > 0 && current_indent < last_indent) {
            (void) array_pop(&scanner->indents);
            lexer->result_symbol = DEDENT;
            return true;
        }

        if (valid_symbols[NEWLINE]) {
            if (current_indent > last_indent) {
                array_push(&scanner->indents, current_indent);
            }
            lexer->result_symbol = NEWLINE;
            return true;
        }

    } else if (next_token_is_a_tag && valid_symbols[DEDENT] && current_indent < last_indent &&
               scanner->indents.size > 0) {
        (void) array_pop(&scanner->indents);
        lexer->result_symbol = DEDENT;
        return true;
    }

    if (white_space) {
        if (nbsp && valid_symbols[NBSP]) {
            lexer->result_symbol = NBSP;
            return true;
        }

        if (valid_symbols[WHITESPACE]) {
            lexer->result_symbol = WHITESPACE;
            return true;
        }
    }

    return false;
}

unsigned tree_sitter_xpo_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    size_t size = 0;

    buffer[size++] = (char)(scanner->row & 0xFF);
    buffer[size++] = (char)((scanner->row >> 8) & 0xFF);

    uint32_t iter = 1;
    for (; iter < scanner->indents.size && size < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; ++iter) {
        uint16_t indent_value = *array_get(&scanner->indents, iter);
        buffer[size++] = (char)(indent_value & 0xFF);
        buffer[size++] = (char)((indent_value >> 8) & 0xFF);
    }

    return size;
}

void tree_sitter_xpo_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;

    if (length > 0) {
        size_t size = 0;

        uint16_t row_value = (unsigned char)buffer[size++];
        row_value |= ((unsigned char)buffer[size++] << 8);

        scanner->row = row_value;

        array_delete(&scanner->indents);
        array_push(&scanner->indents, 0);

        for (; size + 1 < length; size += 2) {
            uint16_t indent_value = (unsigned char)buffer[size] | ((unsigned char)buffer[size + 1] << 8);
            array_push(&scanner->indents, indent_value);
        }
    }
}

void *tree_sitter_xpo_external_scanner_create() {
    Scanner *scanner = calloc(1, sizeof(Scanner));
    array_init(&scanner->indents);
    scanner->row = 1;
    tree_sitter_xpo_external_scanner_deserialize(scanner, NULL, 0);
    return scanner;
}

void tree_sitter_xpo_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    array_delete(&scanner->indents);
    free(scanner);
}
