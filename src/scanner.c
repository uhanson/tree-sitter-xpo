#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"

enum TokenType {
    INDENT,
    DEDENT,
    NEWLINE,
};

typedef struct {
    Array(uint32_t) indents;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

bool tree_sitter_xpo_external_scanner_scan(
    void *payload, TSLexer *lexer, const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    lexer->mark_end(lexer);

    bool found_end_of_line = false;
    uint16_t indent_length = 0;
    for (;;) {
        if (lexer->lookahead == '\n') {
            found_end_of_line = true;
            indent_length = 0;
            skip(lexer);
        } else if (lexer->lookahead == ' ') {
            indent_length++;
            skip(lexer);
        } else if (lexer->lookahead == '\r' || lexer->lookahead == '\f') {
            indent_length = 0;
            skip(lexer);
        } else if (lexer->lookahead == '\t') {
            indent_length += 8;
            skip(lexer);
        } else if (lexer->lookahead == ';' &&
                   (valid_symbols[INDENT] || valid_symbols[DEDENT] ||
                    valid_symbols[NEWLINE])) {
            // If we haven't found an EOL yet,
            // then this is a comment after an expression:
            //   foo = bar # comment
            // Just return, since we don't want to generate an indent/dedent
            // token.
            if (!found_end_of_line) {
                return false;
            }
            while (lexer->lookahead && lexer->lookahead != '\n') {
                skip(lexer);
            }
            skip(lexer);
            indent_length = 0;
        } else if (lexer->eof(lexer)) {
            indent_length = 0;
            found_end_of_line = true;
            break;
        } else {
            break;
        }
    }

    if (found_end_of_line) {
        if (scanner->indents.size > 0) {
            uint16_t current_indent_length = *array_back(&scanner->indents);

            if (valid_symbols[INDENT] &&
                indent_length > current_indent_length) {
                array_push(&scanner->indents, indent_length);
                lexer->result_symbol = INDENT;
                return true;
            }

            bool next_tok_is_string_start = lexer->lookahead == '#';

            if (valid_symbols[DEDENT] &&
                indent_length < current_indent_length) {
                array_pop(&scanner->indents);
                lexer->result_symbol = DEDENT;
                return true;
            }
        }

        if (valid_symbols[NEWLINE]) {
            lexer->result_symbol = NEWLINE;
            return true;
        }
    }

    return false;
}

unsigned
tree_sitter_python_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    size_t size = 0;

    uint32_t iter = 1;
    for (; iter < scanner->indents.size &&
           size < TREE_SITTER_SERIALIZATION_BUFFER_SIZE;
         ++iter) {
        uint16_t indent_value = *array_get(&scanner->indents, iter);
        buffer[size++] = (char)(indent_value & 0xFF);
        buffer[size++] = (char)((indent_value >> 8) & 0xFF);
    }

    return size;
}

void tree_sitter_python_external_scanner_deserialize(
    void *payload, const char *buffer, unsigned length
) {
    Scanner *scanner = (Scanner *)payload;

    array_delete(&scanner->indents);
    array_push(&scanner->indents, 0);

    if (length > 0) {
        size_t size = 0;

        for (; size + 1 < length; size += 2) {
            uint16_t indent_value = (unsigned char)buffer[size] |
                                    ((unsigned char)buffer[size + 1] << 8);
            array_push(&scanner->indents, indent_value);
        }
    }
}

void *tree_sitter_python_external_scanner_create() {
    Scanner *scanner = calloc(1, sizeof(Scanner));
    array_init(&scanner->indents);
    tree_sitter_python_external_scanner_deserialize(scanner, NULL, 0);
    return scanner;
}

void tree_sitter_python_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    array_delete(&scanner->indents);
    free(scanner);
}
