// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#ifndef AST_H
#define AST_H

typedef enum {
    // Program structure
    AST_PROGRAM,
    AST_FUNCTION_DECL,
    AST_BLOCK,
    
    // Statements
    AST_VAR_DECL,
    AST_ASSIGNMENT,
    AST_IF_STMT,
    AST_RETURN_STMT,
    AST_EXPR_STMT,
    
    // Expressions
    AST_BINARY_OP,
    AST_FUNCTION_CALL,
    AST_IDENTIFIER,
    AST_NUMBER,
    AST_STRING,
} ASTNodeType;

typedef struct ASTNode{
    ASTNodeType type;
    int line;
    int column;
    
    // Node data (union saves memory - only one field is used at a time)
    union {
        // For literals (NUMBER, STRING, IDENTIFIER)
        char *value;
        
        // For binary operations (+, -, *, /, ==, etc.)
        struct {
            struct ASTNode *left;
            char *op;
            struct ASTNode *right;
        } binary;
        
        // For variable declarations (let x = 5)
        struct {
            char *name;
            struct ASTNode *initializer;  // Can be NULL
        } var_decl;
        
        // For assignments (x = 5)
        struct {
            char *name;
            struct ASTNode *value;
        } assignment;
        
        // For function declarations
        struct {
            char *name;
            char **params;           // Array of parameter names
            int param_count;
            struct ASTNode *body;    // Block node
        } function;
        
        // For if statements
        struct {
            struct ASTNode *condition;
            struct ASTNode *then_branch;
            struct ASTNode *else_branch;  // Can be NULL
        } if_stmt;
        
        // For function calls
        struct {
            char *name;
            struct ASTNode **args;
            int arg_count;
        } call;
        
        // For blocks and program (list of statements)
        struct {
            struct ASTNode **statements;
            int count;
            int capacity;
        } block;
        
    } data;
} ASTNode;


ASTNode* create_number_node(const char *value, int line, int column);
ASTNode* create_string_node(const char *value, int line, int column);
ASTNode* create_identifier_node(const char *name, int line, int column);
ASTNode* create_binary_op_node(ASTNode *left, const char *op, ASTNode *right, int line, int column);
ASTNode* create_var_decl_node(const char *name, ASTNode *initializer, int line, int column);
ASTNode* create_assignment_node(const char *name, ASTNode *value, int line, int column);
ASTNode* create_function_node(const char *name, char **params, int param_count, ASTNode *body, int line, int column);
ASTNode* create_if_node(ASTNode *condition, ASTNode *then_branch, ASTNode *else_branch, int line, int column);
ASTNode* create_block_node(int line, int column);
ASTNode* create_program_node();
void add_statement_to_block(ASTNode *block, ASTNode *stmt);
void free_ast(ASTNode *node);
void print_ast(ASTNode *node, int indent);

#endif