/**
 * @file Dynamics Ax 2009 Export file
 * @author Andrey Anikin <andrey.anikin@gmail.com>
 * @license MIT
 */

<reference types="tree-sitter-cli/dsl" />
// @ts-check
/* eslint-enable no-multi-spaces */

module.exports = grammar({
  name: 'xpo',

  extras: $ => [
    /\uFEFF/,
    /\uFFEF/,
    /[ \t]+/,
  ],

  externals: $ => [
    $._indent,
    $._dedent,
    $._newline,
  ],

  rules: {
    source_file: $ =>
      seq(
        /Exportfile for AOT version 1\.0 or later[ \t\n\r]*/,
        /Formatversion: 1[ \t\n\r]*/,
        repeat(
          seq(
            choice(
              $.comment,
              $.delimiter,
              seq('#', $.text),
              $.tag),
            /[ \t\n\r]*/))),

    tag: $ =>
      seq(
        $.name,
        /[ \t]*/,
        $.value),

    text: _ => /[^\n\r]*/,

    comment: _ => /;[^\n\r]*/,

    delimiter: _ => /\*\*\*[^\n\r]*/,

    name: _ => /[A-Za-z0-9:*]+/,

    value: $ => /[^\n\r]*/,
  }
});
