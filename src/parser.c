#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 31
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 6
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  aux_sym_file_token1 = 1,
  aux_sym_file_token2 = 2,
  sym_text = 3,
  sym_comment = 4,
  sym_delimiter = 5,
  sym_ident = 6,
  sym_value = 7,
  sym__indent = 8,
  sym__dedent = 9,
  sym__nbsp = 10,
  sym__newline = 11,
  sym__whitespace = 12,
  sym__error_sentinel = 13,
  sym_file = 14,
  sym_tag = 15,
  sym_subs = 16,
  aux_sym_file_repeat1 = 17,
  aux_sym_subs_repeat1 = 18,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_file_token1] = "file_token1",
  [aux_sym_file_token2] = "file_token2",
  [sym_text] = "text",
  [sym_comment] = "comment",
  [sym_delimiter] = "delimiter",
  [sym_ident] = "ident",
  [sym_value] = "value",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__nbsp] = "_nbsp",
  [sym__newline] = "_newline",
  [sym__whitespace] = "_whitespace",
  [sym__error_sentinel] = "_error_sentinel",
  [sym_file] = "file",
  [sym_tag] = "tag",
  [sym_subs] = "subs",
  [aux_sym_file_repeat1] = "file_repeat1",
  [aux_sym_subs_repeat1] = "subs_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_file_token1] = aux_sym_file_token1,
  [aux_sym_file_token2] = aux_sym_file_token2,
  [sym_text] = sym_text,
  [sym_comment] = sym_comment,
  [sym_delimiter] = sym_delimiter,
  [sym_ident] = sym_ident,
  [sym_value] = sym_value,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym__nbsp] = sym__nbsp,
  [sym__newline] = sym__newline,
  [sym__whitespace] = sym__whitespace,
  [sym__error_sentinel] = sym__error_sentinel,
  [sym_file] = sym_file,
  [sym_tag] = sym_tag,
  [sym_subs] = sym_subs,
  [aux_sym_file_repeat1] = aux_sym_file_repeat1,
  [aux_sym_subs_repeat1] = aux_sym_subs_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_file_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_file_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_delimiter] = {
    .visible = true,
    .named = true,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [sym_value] = {
    .visible = true,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym__nbsp] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym__error_sentinel] = {
    .visible = false,
    .named = true,
  },
  [sym_file] = {
    .visible = true,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_subs] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_subs_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 10,
  [15] = 12,
  [16] = 16,
  [17] = 9,
  [18] = 18,
  [19] = 19,
  [20] = 11,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 19,
  [27] = 22,
  [28] = 21,
  [29] = 18,
  [30] = 25,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(31);
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == '*') ADVANCE(41);
      if (lookahead == ';') ADVANCE(35);
      if (lookahead == 'E') ADVANCE(63);
      if (lookahead == 'F') ADVANCE(52);
      if (lookahead == 0xfeff ||
          lookahead == 0xffef) SKIP(0);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(30);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(19);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(23);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == 0xfeff ||
          lookahead == 0xffef) SKIP(6);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == '0') ADVANCE(5);
      END_STATE();
    case 9:
      if (lookahead == '1') ADVANCE(33);
      END_STATE();
    case 10:
      if (lookahead == '1') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == 'A') ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == 'O') ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == 'T') ADVANCE(2);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(29);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(26);
      END_STATE();
    case 17:
      if (lookahead == 'f') ADVANCE(21);
      END_STATE();
    case 18:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 20:
      if (lookahead == 'n') ADVANCE(4);
      END_STATE();
    case 21:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 22:
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 23:
      if (lookahead == 'o') ADVANCE(27);
      END_STATE();
    case 24:
      if (lookahead == 'r') ADVANCE(1);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 26:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 27:
      if (lookahead == 'r') ADVANCE(3);
      END_STATE();
    case 28:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 29:
      if (lookahead == 't') ADVANCE(16);
      END_STATE();
    case 30:
      if (lookahead == 'v') ADVANCE(15);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_file_token1);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_file_token2);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_text);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_delimiter);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(37);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_delimiter);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == ' ') ADVANCE(17);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == ' ') ADVANCE(9);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '*') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '*') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == ':') ADVANCE(39);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(61);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(38);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(58);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'f') ADVANCE(47);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'i') ADVANCE(49);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'i') ADVANCE(53);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(44);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'm') ADVANCE(43);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'n') ADVANCE(42);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'o') ADVANCE(56);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'o') ADVANCE(51);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'o') ADVANCE(57);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'p') ADVANCE(54);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(50);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(60);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(59);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 's') ADVANCE(48);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(46);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(62);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'v') ADVANCE(45);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'x') ADVANCE(55);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '*' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_value);
      if (lookahead == 0xfeff ||
          lookahead == 0xffef) ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(66);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_value);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(66);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 6, .external_lex_state = 3},
  [10] = {.lex_state = 6, .external_lex_state = 4},
  [11] = {.lex_state = 6, .external_lex_state = 5},
  [12] = {.lex_state = 6, .external_lex_state = 4},
  [13] = {.lex_state = 6, .external_lex_state = 4},
  [14] = {.lex_state = 6, .external_lex_state = 4},
  [15] = {.lex_state = 6, .external_lex_state = 4},
  [16] = {.lex_state = 0, .external_lex_state = 2},
  [17] = {.lex_state = 0, .external_lex_state = 6},
  [18] = {.lex_state = 6, .external_lex_state = 4},
  [19] = {.lex_state = 6, .external_lex_state = 4},
  [20] = {.lex_state = 0, .external_lex_state = 7},
  [21] = {.lex_state = 6, .external_lex_state = 4},
  [22] = {.lex_state = 6, .external_lex_state = 4},
  [23] = {.lex_state = 0, .external_lex_state = 2},
  [24] = {.lex_state = 0, .external_lex_state = 8},
  [25] = {.lex_state = 65, .external_lex_state = 2},
  [26] = {.lex_state = 0, .external_lex_state = 8},
  [27] = {.lex_state = 0, .external_lex_state = 8},
  [28] = {.lex_state = 0, .external_lex_state = 8},
  [29] = {.lex_state = 0, .external_lex_state = 8},
  [30] = {.lex_state = 65, .external_lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_file_token1] = ACTIONS(1),
    [aux_sym_file_token2] = ACTIONS(1),
    [sym_text] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_delimiter] = ACTIONS(1),
    [sym_ident] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym__nbsp] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__whitespace] = ACTIONS(3),
    [sym__error_sentinel] = ACTIONS(1),
  },
  [1] = {
    [sym_file] = STATE(23),
    [sym_tag] = STATE(24),
    [aux_sym_file_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(5),
    [aux_sym_file_token1] = ACTIONS(7),
    [aux_sym_file_token2] = ACTIONS(9),
    [sym_comment] = ACTIONS(11),
    [sym_delimiter] = ACTIONS(11),
    [sym_ident] = ACTIONS(13),
    [sym__whitespace] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      sym_ident,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      aux_sym_file_token2,
    STATE(5), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(11), 2,
      sym_comment,
      sym_delimiter,
  [23] = 6,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      sym_ident,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(11), 2,
      sym_comment,
      sym_delimiter,
  [43] = 6,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      sym_ident,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(8), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(11), 2,
      sym_comment,
      sym_delimiter,
  [63] = 6,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      sym_ident,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(11), 2,
      sym_comment,
      sym_delimiter,
  [83] = 6,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      sym_ident,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(11), 2,
      sym_comment,
      sym_delimiter,
  [103] = 6,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(26), 1,
      sym_ident,
    STATE(7), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(23), 2,
      sym_comment,
      sym_delimiter,
  [123] = 6,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      sym_ident,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_file_repeat1,
    STATE(24), 1,
      sym_tag,
    ACTIONS(11), 2,
      sym_comment,
      sym_delimiter,
  [143] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(33), 1,
      sym__indent,
    ACTIONS(35), 1,
      sym__nbsp,
    STATE(19), 1,
      sym_subs,
    ACTIONS(31), 3,
      sym__dedent,
      sym_text,
      sym_ident,
  [161] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(37), 1,
      sym_text,
    ACTIONS(39), 1,
      sym_ident,
    ACTIONS(41), 1,
      sym__dedent,
    STATE(12), 2,
      sym_tag,
      aux_sym_subs_repeat1,
  [178] = 4,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(33), 1,
      sym__indent,
    STATE(21), 1,
      sym_subs,
    ACTIONS(43), 3,
      sym__dedent,
      sym_text,
      sym_ident,
  [193] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(39), 1,
      sym_ident,
    ACTIONS(45), 1,
      sym_text,
    ACTIONS(47), 1,
      sym__dedent,
    STATE(13), 2,
      sym_tag,
      aux_sym_subs_repeat1,
  [210] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(49), 1,
      sym_text,
    ACTIONS(52), 1,
      sym_ident,
    ACTIONS(55), 1,
      sym__dedent,
    STATE(13), 2,
      sym_tag,
      aux_sym_subs_repeat1,
  [227] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(39), 1,
      sym_ident,
    ACTIONS(57), 1,
      sym_text,
    ACTIONS(59), 1,
      sym__dedent,
    STATE(15), 2,
      sym_tag,
      aux_sym_subs_repeat1,
  [244] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(39), 1,
      sym_ident,
    ACTIONS(45), 1,
      sym_text,
    ACTIONS(61), 1,
      sym__dedent,
    STATE(13), 2,
      sym_tag,
      aux_sym_subs_repeat1,
  [261] = 3,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(63), 1,
      sym_ident,
    ACTIONS(21), 3,
      ts_builtin_sym_end,
      sym_comment,
      sym_delimiter,
  [273] = 5,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(31), 1,
      sym__newline,
    ACTIONS(65), 1,
      sym__indent,
    ACTIONS(67), 1,
      sym__nbsp,
    STATE(26), 1,
      sym_subs,
  [289] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(69), 3,
      sym__dedent,
      sym_text,
      sym_ident,
  [298] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(71), 3,
      sym__dedent,
      sym_text,
      sym_ident,
  [307] = 4,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(43), 1,
      sym__newline,
    ACTIONS(65), 1,
      sym__indent,
    STATE(28), 1,
      sym_subs,
  [320] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(73), 3,
      sym__dedent,
      sym_text,
      sym_ident,
  [329] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(75), 3,
      sym__dedent,
      sym_text,
      sym_ident,
  [338] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
  [345] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(79), 1,
      sym__newline,
  [352] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(81), 1,
      sym_value,
  [359] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(71), 1,
      sym__newline,
  [366] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(75), 1,
      sym__newline,
  [373] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(73), 1,
      sym__newline,
  [380] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(69), 1,
      sym__newline,
  [387] = 2,
    ACTIONS(3), 1,
      sym__whitespace,
    ACTIONS(83), 1,
      sym_value,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 23,
  [SMALL_STATE(4)] = 43,
  [SMALL_STATE(5)] = 63,
  [SMALL_STATE(6)] = 83,
  [SMALL_STATE(7)] = 103,
  [SMALL_STATE(8)] = 123,
  [SMALL_STATE(9)] = 143,
  [SMALL_STATE(10)] = 161,
  [SMALL_STATE(11)] = 178,
  [SMALL_STATE(12)] = 193,
  [SMALL_STATE(13)] = 210,
  [SMALL_STATE(14)] = 227,
  [SMALL_STATE(15)] = 244,
  [SMALL_STATE(16)] = 261,
  [SMALL_STATE(17)] = 273,
  [SMALL_STATE(18)] = 289,
  [SMALL_STATE(19)] = 298,
  [SMALL_STATE(20)] = 307,
  [SMALL_STATE(21)] = 320,
  [SMALL_STATE(22)] = 329,
  [SMALL_STATE(23)] = 338,
  [SMALL_STATE(24)] = 345,
  [SMALL_STATE(25)] = 352,
  [SMALL_STATE(26)] = 359,
  [SMALL_STATE(27)] = 366,
  [SMALL_STATE(28)] = 373,
  [SMALL_STATE(29)] = 380,
  [SMALL_STATE(30)] = 387,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file, 2, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_file_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_file_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_file_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file, 3, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_subs_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_subs_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_subs_repeat1, 2, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_file_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subs, 3, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 4, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subs, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__indent = 0,
  ts_external_token__dedent = 1,
  ts_external_token__nbsp = 2,
  ts_external_token__newline = 3,
  ts_external_token__whitespace = 4,
  ts_external_token__error_sentinel = 5,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
  [ts_external_token__nbsp] = sym__nbsp,
  [ts_external_token__newline] = sym__newline,
  [ts_external_token__whitespace] = sym__whitespace,
  [ts_external_token__error_sentinel] = sym__error_sentinel,
};

static const bool ts_external_scanner_states[9][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__nbsp] = true,
    [ts_external_token__newline] = true,
    [ts_external_token__whitespace] = true,
    [ts_external_token__error_sentinel] = true,
  },
  [2] = {
    [ts_external_token__whitespace] = true,
  },
  [3] = {
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__nbsp] = true,
    [ts_external_token__whitespace] = true,
  },
  [4] = {
    [ts_external_token__dedent] = true,
    [ts_external_token__whitespace] = true,
  },
  [5] = {
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__whitespace] = true,
  },
  [6] = {
    [ts_external_token__indent] = true,
    [ts_external_token__nbsp] = true,
    [ts_external_token__newline] = true,
    [ts_external_token__whitespace] = true,
  },
  [7] = {
    [ts_external_token__indent] = true,
    [ts_external_token__newline] = true,
    [ts_external_token__whitespace] = true,
  },
  [8] = {
    [ts_external_token__newline] = true,
    [ts_external_token__whitespace] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_xpo_external_scanner_create(void);
void tree_sitter_xpo_external_scanner_destroy(void *);
bool tree_sitter_xpo_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_xpo_external_scanner_serialize(void *, char *);
void tree_sitter_xpo_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_xpo(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_xpo_external_scanner_create,
      tree_sitter_xpo_external_scanner_destroy,
      tree_sitter_xpo_external_scanner_scan,
      tree_sitter_xpo_external_scanner_serialize,
      tree_sitter_xpo_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
