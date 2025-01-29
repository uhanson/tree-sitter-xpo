#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"
#include <stdio.h>

enum TokenType {
    INDENT,
    DEDENT,
    NEWLINE,
    WHITESPACE,
    ERROR_SENTINEL,
};

typedef struct {
    Array(uint32_t) indents;
    bool found_end_of_line;
    int row;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

bool tree_sitter_xpo_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    if (false && valid_symbols[ERROR_SENTINEL]) {
        while (lexer->lookahead != '\n' && !lexer->eof(lexer))
            skip(lexer);

        fprintf(stderr, ": error\n");
    }

    lexer->mark_end(lexer);

    fprintf(
        stderr, "%3d/%3d %c (%02X): %s%s%s%s%s", scanner->row, lexer->get_column(lexer),
        lexer->lookahead >= 20 ? lexer->lookahead : 'ø', lexer->lookahead, valid_symbols[INDENT] ? "I" : " ",
        valid_symbols[DEDENT] ? "D" : " ", valid_symbols[NEWLINE] ? "N" : " ", valid_symbols[WHITESPACE] ? "W" : " ",
        valid_symbols[ERROR_SENTINEL] ? "E" : " "
    );

    if (lexer->lookahead == '\n')
        scanner->row++;

    bool white_space = lexer->lookahead == '\n' || lexer->lookahead == ' ' || lexer->lookahead == '\r' ||
                       lexer->lookahead == '\f' || lexer->lookahead == '\t';

    scanner->found_end_of_line = scanner->found_end_of_line || lexer->lookahead == '\n' || lexer->eof(lexer);

    fprintf(
        stderr, " ident %d (%d)", scanner->indents.size, scanner->indents.size > 0 ? *array_back(&scanner->indents) : 0
    );

    fprintf(stderr, " %s%s", white_space ? "<ws>" : "", scanner->found_end_of_line ? "<eol>" : "");

    if (white_space)
        skip(lexer);

    if (white_space && valid_symbols[WHITESPACE]) {
        lexer->mark_end(lexer);
        lexer->result_symbol = WHITESPACE;
        fprintf(stderr, ": whitespace %c %02x\n", lexer->lookahead >= 20 ? lexer->lookahead : 'ø', lexer->lookahead);
        return true;
    }

    if (scanner->found_end_of_line) {
        if (scanner->indents.size > 0) {
            uint16_t last_indent = *array_back(&scanner->indents);
            uint16_t current_indent = lexer->get_column(lexer);

            if (valid_symbols[INDENT] && current_indent > last_indent) {
                array_push(&scanner->indents, current_indent);
                lexer->result_symbol = INDENT;
                fprintf(stderr, ": indent\n");
                return true;
            }

            if (valid_symbols[DEDENT] && current_indent < last_indent) {
                while (scanner->indents.size > 0 && current_indent < array_pop(&scanner->indents))
                    ;
                lexer->result_symbol = DEDENT;
                fprintf(stderr, ": dedent\n");
                return true;
            }
        }

        if (valid_symbols[NEWLINE]) {
            lexer->result_symbol = NEWLINE;
            fprintf(stderr, ": newline\n");
            return true;
        }
    }

    scanner->found_end_of_line = false;

    fprintf(stderr, ": -\n");
    return false;
}

unsigned tree_sitter_xpo_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    size_t size = 0;

    buffer[size++] = (char)scanner->found_end_of_line;
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

        scanner->found_end_of_line = (bool)buffer[size++];

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
    scanner->found_end_of_line = false;
    scanner->row = 0;
    tree_sitter_xpo_external_scanner_deserialize(scanner, NULL, 0);
    return scanner;
}

void tree_sitter_xpo_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    array_delete(&scanner->indents);
    free(scanner);
}
