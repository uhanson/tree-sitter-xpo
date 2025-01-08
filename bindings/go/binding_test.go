package tree_sitter_xpo_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_xpo "github.com/tree-sitter/tree-sitter-xpo/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_xpo.Language())
	if language == nil {
		t.Errorf("Error loading Xpo grammar")
	}
}
