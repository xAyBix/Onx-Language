# ARCHITECTURE FILE

The architecture file documents the structure, variables, functions, and execution flow of the **ONX Language**.

---

## 1. PROJECT STRUCTURE

Onx-Language/ <br>
├── assets/ # Contains materials <br>
├── build/ # Where project builds <br>
├── includes/ # Contains header files <br>
├── src/ <br>
│ ├── tokenizer/ <br>
│ │ ├── tokenizer.c # Characters → tokens <br>
│ │ └── matcher.c # Token types enum <br>
│ ├── parser/ <br>
│ │ └── parser.c # Tokens → AST <br>
│ ├── ast/ <br>
│ │ └── ast_nodes.c # AST node structs (program_node, identifier_node, etc.) <br>
│ ├── gen/ <br>
│ │ ├── analyzer.c # Type checking, symbol resolution <br>
│ │ └── code_generator.c # Generate a code in c <br>
│ ├── io/ <br>
│ │ └── input.c # Files reading <br>
│ ├── commands/ <br>
│ │ ├── commands_manager.c # Command checking <br>
│ │ ├── help.c # Shows help menu <br>
│ │ ├── version.c # Shows version <br>
│ │ └── easter_eggs.c # Special commands <br>
│ ├── orchestration/ <br>
│ │ └── orchestrator.c # Organize tasks <br>
│ └── onxc.c # # Entry point <br>
└── test/ <br>

---

## 2. EXECUTION FLOW

Source file (.onx) → Compiler's entry point (onxc.c::main) → <br>
Check command (commands/commands_manager.c::check_for_command_errors) → <br>
Start Compilation (orchestration/orchestrator.c::compile) → <br>
Read files (io/input.c::filesReader) →<br>
Tokenize files content (tokenizer/tokenizer.c::tokenize) → <br>
Parse tokens to AST (parser/parser.c::parse) → <br>
C code generation (gen/code_generator.c::generate) → <br>
Executable generation (io/output.c::build)<br>

---

## 3. FUNCTIONS