# lexical_analyser
A simple and clean Lexical Analyzer built in C that reads a C source file and breaks it into tokens like keywords, identifiers, operators, and constants. It also catches common mistakes like unmatched brackets and invalid literals — a mini step into compiler design.

Working Description

This project implements a modular Lexical Analyzer in C that simulates the first phase of a compiler. The program reads a C source file as input, processes it line by line, and scans each character to generate meaningful tokens. It identifies and classifies keywords, identifiers, operators, assignment operators, constants (integer, float, binary, octal, hexadecimal), symbols, special characters, string literals, and character constants.

The analyzer ignores delimiters such as spaces, tabs, and newline characters while constructing tokens dynamically using pointer-based traversal. It uses separate modules to manage token definitions and classification logic, improving code maintainability and readability.

In addition to token generation, the analyzer performs structural error detection. It checks for unmatched parentheses (), braces {}, and brackets [] using counters. It also detects unterminated string literals, invalid character constants, and malformed numeric literals. While it does not perform full syntax analysis, it demonstrates how lexical analysis prepares structured input for the next compiler phase.

This project strengthened my understanding of compiler phases, tokenization logic, modular programming, file handling, and error detection mechanisms in C.
