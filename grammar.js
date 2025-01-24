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

  extras: $ => [
    /\uFEFF/,
    /\uFFEF/,
    /\s/,
  ],

  externals: $ => [
    $._indent,
    $._dedent,
    $._newline,
  ],

  rules: {
    source_file: $ => seq(
      /Exportfile for AOT version 1\.0 or later[ \t\n\r]*/,
      /Formatversion: 1[ \t\n\r]*/,
      repeat(
        seq(
          choice(
            $.comment, 
            $.delimiter, 
            $._tag),
          $._newline))),

    _tag: $ => choice($.text, $.tag),

    text: $ => /#[^\n\r]*/,

    tag: $ => 
      seq(
        $.name, optional(seq(/\s+/, $.value)), $._newline, 
        optional($.subs)),

    subs: $ => 
      seq(
        $._indent,
        repeat($._tag),
        $._dedent),

    comment: _ => /;[^\n\r]*/,

    delimiter: _ => /\*\*\*[^\n\r]*/,

    name: _ => /[A-Za-z0-9:*_]+/,

    value: _ => /[^\n\r]*/,
  }
});
