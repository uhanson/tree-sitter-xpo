#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"

// #define DEBUG

#ifdef DEBUG
#include <ctype.h>
#endif

#define INDENT_SIZE 2

enum TokenType {
    INDENT,
    DEDENT,
    NBSP,
    NEWLINE,
    WHITESPACE,
    ERROR_SENTINEL,
};

typedef struct {
    uint32_t last_indent;
#ifdef DEBUG
    uint32_t row;
#endif
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

bool tree_sitter_xpo_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    lexer->mark_end(lexer);
#ifdef DEBUG
    char lookahead_at_start = lexer->lookahead;
#endif

    bool nbsp = true;
    bool white_space = false;
    bool found_end_of_line = false;
    uint32_t current_indent = lexer->get_column(lexer);
    for (;;) {
        if (lexer->lookahead == '\n') {
            found_end_of_line = true;
            white_space = true;
            current_indent = 0;
            nbsp = false;
            skip(lexer);
#ifdef DEBUG
            scanner->row++;
#endif
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

    bool next_token_is_a_comment = lexer->lookahead == ';';

#ifdef DEBUG
    fprintf(stderr, "% 3d/% 3d (% 3d): ", scanner->row, current_indent, scanner->last_indent);

    fprintf(stderr,
            "%c%c%c%c%c%c|%c%c%c ",
            valid_symbols[INDENT] ? 'I' : ' ',
            valid_symbols[DEDENT] ? 'D' : ' ',
            valid_symbols[NBSP] ? 'B' : ' ',
            valid_symbols[NEWLINE] ? 'N' : ' ',
            valid_symbols[WHITESPACE] ? 'W' : ' ',
            valid_symbols[ERROR_SENTINEL] ? 'E' : ' ',
            white_space ? '_' : ' ',
            found_end_of_line ? '$' : ' ',
            next_token_is_a_comment ? ';' :' ');

    if (isprint(lookahead_at_start)) {
        fprintf(stderr, "'%c'..", lookahead_at_start);
    } else {
        fprintf(stderr, " %02x..", lookahead_at_start);
    }

    if (isprint(lexer->lookahead)) {
        fprintf(stderr, "'%c' ", lexer->lookahead);
    } else {
        fprintf(stderr, " %02x ", lexer->lookahead);
    }
#endif
    if (valid_symbols[DEDENT] && current_indent < scanner->last_indent && !next_token_is_a_comment) {
        scanner->last_indent -= INDENT_SIZE;
        lexer->result_symbol = DEDENT;
#ifdef DEBUG
        fprintf(stderr, ": DEDENT %d->%d\n", scanner->last_indent, current_indent);
#endif
        return true;
    }

    if (valid_symbols[NEWLINE] && current_indent == scanner->last_indent && !next_token_is_a_comment) {
#ifdef DEBUG
        fprintf(stderr, ": NEWLINE\n");
#endif
        lexer->result_symbol = NEWLINE;
        return true;
    }

    if (found_end_of_line) {
        if (valid_symbols[INDENT] && current_indent > scanner->last_indent + 1) {
            scanner->last_indent += INDENT_SIZE;
            lexer->result_symbol = INDENT;
#ifdef DEBUG
            fprintf(stderr, ": INDENT %d->%d\n", scanner->last_indent, current_indent);
#endif
            return true;
        }

        if (valid_symbols[NEWLINE]) {
#ifdef DEBUG
            fprintf(stderr, ": NEWLINE");
#endif
            if (!next_token_is_a_comment && current_indent > scanner->last_indent) {
#ifdef DEBUG
                fprintf(stderr, " %d->%d", scanner->last_indent, current_indent & ~0x1);
#endif
                scanner->last_indent = current_indent & ~0x1;
            }
#ifdef DEBUG
            fprintf(stderr, "\n");
#endif
            lexer->result_symbol = NEWLINE;
            return true;
        }
    }

    if (white_space) {
        if (nbsp && valid_symbols[NBSP]) {
            lexer->result_symbol = NBSP;
#ifdef DEBUG
            fprintf(stderr, ": NBSP\n");
#endif
            return true;
        }

        if (valid_symbols[WHITESPACE]) {
            lexer->result_symbol = WHITESPACE;
#ifdef DEBUG
            fprintf(stderr, ": WHITESPACE\n");
#endif
            return true;
        }
    }

#ifdef DEBUG
    fprintf(stderr, ": ---\n");
#endif

    return false;
}

unsigned tree_sitter_xpo_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    size_t size = 0;

    buffer[size++] = (char)(scanner->last_indent & 0xFF);
    buffer[size++] = (char)((scanner->last_indent >> 8) & 0xFF);
    buffer[size++] = (char)((scanner->last_indent >> 16) & 0xFF);
    buffer[size++] = (char)((scanner->last_indent >> 24) & 0xFF);
#ifdef DEBUG
    buffer[size++] = (char)(scanner->row & 0xFF);
    buffer[size++] = (char)((scanner->row >> 8) & 0xFF);
    buffer[size++] = (char)((scanner->row >> 16) & 0xFF);
    buffer[size++] = (char)((scanner->row >> 24) & 0xFF);
#endif

    return size;
}

void tree_sitter_xpo_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;

    if (length > 0) {
        size_t size = 0;
        scanner->last_indent = (unsigned char)buffer[size++];
        scanner->last_indent = scanner->last_indent | ((unsigned char)buffer[size++] << 8);
        scanner->last_indent = scanner->last_indent | ((unsigned char)buffer[size++] << 16);
        scanner->last_indent = scanner->last_indent | ((unsigned char)buffer[size++] << 24);
#ifdef DEBUG
        scanner->row = (unsigned char)buffer[size++];
        scanner->row = scanner->row | ((unsigned char)buffer[size++] << 8);
        scanner->row = scanner->row | ((unsigned char)buffer[size++] << 16);
        scanner->row = scanner->row | ((unsigned char)buffer[size++] << 24);
#endif
    }
}

void *tree_sitter_xpo_external_scanner_create() {
    Scanner *scanner = calloc(1, sizeof(Scanner));
    scanner->last_indent = 0;
#ifdef DEBUG
    scanner->row = 0;
#endif
    tree_sitter_xpo_external_scanner_deserialize(scanner, NULL, 0);
    return scanner;
}

void tree_sitter_xpo_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    free(scanner);
}
