// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterXpo",
    products: [
        .library(name: "TreeSitterXpo", targets: ["TreeSitterXpo"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterXpo",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterXpoTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterXpo",
            ],
            path: "bindings/swift/TreeSitterXpoTests"
        )
    ],
    cLanguageStandard: .c11
)
