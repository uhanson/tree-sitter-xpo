/**
 * @file Dynamics Ax 2009 Export file
 * @author Andrey Anikin <andrey.anikin@gmail.com>
 * @license MIT
 */

// @ts-ignore
// <reference types="tree-sitter-cli/dsl" />
// @ts-check
/* eslint-enable no-multi-spaces */

module.exports = grammar({
  name: 'xpo',

  externals: $ => [
    $._indent,
    $._dedent,
    $._nbsp,
    $._newline,
    $._whitespace,
    $._error_sentinel,
  ],

  extras: $ => [
    /\uFEFF/,
    /\uFFEF/,
    $._whitespace,
  ],

  rules: {
    file: $ => seq(
      optional(/Exportfile for AOT version 1\.0 or later/),
      optional(/Formatversion: 1/),
      repeat(seq(
        choice(
          $.comment,
          $.delimiter,
          $.tag),
        $._newline))),

    tag: $ => seq(
      $.ident,
      optional(seq($._nbsp, $.value)),
      optional($.subs)),

    subs: $ => seq(
      $._indent,
      repeat(choice($.text, $.tag)),
      $._dedent),

    text: _ => /#[^\n\r]*/,

    comment: _ => /;[^\n\r]*/,

    delimiter: _ => /\*\*\*[^\n\r]*/,

    ident: _ => /[A-Za-z0-9:*_]+/,

    value: _ => /[^\n\r]*/,
  }
});
