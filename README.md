
![Logo](/assets/images/Onx.png)

# Onx

`Onx` (pronounced “Phoenix”) is a compiled language implemented in C, offering both textual and visual block-based programming, with object-oriented and functional support.

`Onx` is designed with a single goal in mind: to be both **highly readable** and **genuinely powerful**. It aims to lower the entry barrier for beginners while still giving experienced developers expressive tools for building complex systems.

### Features

- Dual programming modes

        Write code using a clean text-based syntax

        Or use a visual, Scratch-like block-based interface

    _Both representations are designed to stay in sync_

- Compiled language

        Compiles to efficient output for better performance

- Dynamic typing

        No need to manually declare types

- Multi-paradigm

        Object-Oriented Programming (OOP)

        Functional Programming (FP)

- Readable by design

        Simple syntax

        Clear structure

        Minimal boilerplate

___
### Program Entry Point

Every `Onx` program begins execution in the **start** function:
```
start(args[]) {
    // Your code here
}
```
> [!NOTE]
> _**args[]** contains command-line arguments_

> [!WARNING]
> The **start** function is mandatory

```
start(args[]) {
    let name = "Akram";
    print("Hello {name} !!"); // Output: Hello Akram !!
}
```

___
### Design Philosophy

`Onx` is built around three core principles:

- Readability first

        Code should read naturally and be easy to understand.

- Power when needed

        Advanced features are available without complicating simple programs.

- Accessibility without limitation

        Beginners can start with blocks, professionals can write text — both target the same language.

### Implementation

- Compiler written in C

- Visual block editor acts as an alternative frontend

- Text and block representations share the same underlying structure

