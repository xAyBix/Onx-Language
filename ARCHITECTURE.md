# ARCHITECTURE FILE

The architecture file documents the structure, variables, functions, and execution flow of the **ONX Language**.

---

## 1. PROJECT STRUCTURE

Onx-Language/
├── assets/ # Contains materials
├── build/ # Where project builds
├── includes/ # Contains header files
├── src/
│ ├── tokenizer/
│ │ ├── tokenizer.c # Characters → tokens
│ │ └── matcher.c # Token types enum
│ ├── parser/
│ │ └── parser.c # Tokens → AST
│ ├── ast/
│ │ └── ast_nodes.c # AST node structs (program_node, identifier_node, etc.)
│ ├── gen/
│ │ ├── analyzer.c # Type checking, symbol resolution
│ │ └── code_generator.c # Generate a code in c
│ ├── io/
│ │ └── input.c # Files reading
│ ├── commands/
│ │ ├── commands_manager.c # Command checking
│ │ ├── help.c # Shows help menu
│ │ ├── version.c # Shows version
│ │ └── easter_eggs.c # Special commands
│ ├── orchestration/
│ │ └── orchestrator.c # Organize tasks
│ └── onxc.c # # Entry point
└── test/ 

---

## 2. EXECUTION FLOW

Source file (.onx) → Compiler's entry point (onxc.c::main) → 
Check command (commands/commands_manager.c::check_for_command_errors) → 
Start Compilation (orchestration/orchestrator.c::compile) → 
Read files (io/input.c::filesReader) →
Tokenize files content (tokenizer/tokenizer.c::tokenize) → 
Parse tokens to AST (parser/parser.c::parse) → 
C code generation (gen/code_generator.c::generate) → 
Executable generation (io/output.c::build)

---

## 3. FUNCTIONS