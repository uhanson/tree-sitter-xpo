import XCTest
import SwiftTreeSitter
import TreeSitterXpo

final class TreeSitterXpoTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_xpo())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Xpo grammar")
    }
}
