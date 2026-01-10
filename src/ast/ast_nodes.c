// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#include "ast/ast_nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


// Create a number literal node
ASTNode* create_number_node(const char *value, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_NUMBER;
    node->line = line;
    node->column = column;
    node->data.value = strdup(value);
    
    return node;
}

// Create a string literal node
ASTNode* create_string_node(const char *value, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_STRING;
    node->line = line;
    node->column = column;
    node->data.value = strdup(value);
    
    return node;
}

// Create an identifier node
ASTNode* create_identifier_node(const char *name, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_IDENTIFIER;
    node->line = line;
    node->column = column;
    node->data.value = strdup(name);
    
    return node;
}

// Create a binary operation node
ASTNode* create_binary_op_node(ASTNode *left, const char *op, ASTNode *right, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_BINARY_OP;
    node->line = line;
    node->column = column;
    node->data.binary.left = left;
    node->data.binary.op = strdup(op);
    node->data.binary.right = right;
    
    return node;
}

// Create a variable declaration node
ASTNode* create_var_decl_node(const char *name, ASTNode *initializer, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_VAR_DECL;
    node->line = line;
    node->column = column;
    node->data.var_decl.name = strdup(name);
    node->data.var_decl.initializer = initializer;
    
    return node;
}

// Create an assignment node
ASTNode* create_assignment_node(const char *name, ASTNode *value, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_ASSIGNMENT;
    node->line = line;
    node->column = column;
    node->data.assignment.name = strdup(name);
    node->data.assignment.value = value;
    
    return node;
}

// Create a function declaration node
ASTNode* create_function_node(const char *name, char **params, int param_count, ASTNode *body, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_FUNCTION_DECL;
    node->line = line;
    node->column = column;
    node->data.function.name = strdup(name);
    node->data.function.params = params;
    node->data.function.param_count = param_count;
    node->data.function.body = body;
    
    return node;
}

// Create an if statement node
ASTNode* create_if_node(ASTNode *condition, ASTNode *then_branch, ASTNode *else_branch, int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_IF_STMT;
    node->line = line;
    node->column = column;
    node->data.if_stmt.condition = condition;
    node->data.if_stmt.then_branch = then_branch;
    node->data.if_stmt.else_branch = else_branch;
    
    return node;
}

// Create a block node
ASTNode* create_block_node(int line, int column) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_BLOCK;
    node->line = line;
    node->column = column;
    node->data.block.statements = NULL;
    node->data.block.count = 0;
    node->data.block.capacity = 0;
    
    return node;
}

// Create a program node (root of AST)
ASTNode* create_program_node() {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
        exit(1);
    }
    
    node->type = AST_PROGRAM;
    node->line = 1;
    node->column = 1;
    node->data.block.statements = NULL;
    node->data.block.count = 0;
    node->data.block.capacity = 0;
    
    return node;
}

// Add a statement to a block
void add_statement_to_block(ASTNode *block, ASTNode *stmt) {
    if (block->type != AST_BLOCK && block->type != AST_PROGRAM) {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mTrying to add statement to non-block node.\n");
        return;
    }
    
    if (block->data.block.count >= block->data.block.capacity) {
        block->data.block.capacity = (block->data.block.capacity == 0) ? 4 : block->data.block.capacity * 2;
        block->data.block.statements = realloc(block->data.block.statements, 
                                               block->data.block.capacity * sizeof(ASTNode*));
        if (!block->data.block.statements) {
            printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mMemory allocation failed.\n");
            exit(1);
        }
    }
    
    block->data.block.statements[block->data.block.count++] = stmt;
}

// Free AST recursively
void free_ast(ASTNode *node) {
    if (!node) return;
    
    switch (node->type) {
        case AST_NUMBER:
        case AST_STRING:
        case AST_IDENTIFIER:
            free(node->data.value);
            break;
            
        case AST_BINARY_OP:
            free_ast(node->data.binary.left);
            free(node->data.binary.op);
            free_ast(node->data.binary.right);
            break;
            
        case AST_VAR_DECL:
            free(node->data.var_decl.name);
            free_ast(node->data.var_decl.initializer);
            break;
            
        case AST_ASSIGNMENT:
            free(node->data.assignment.name);
            free_ast(node->data.assignment.value);
            break;
            
        case AST_FUNCTION_DECL:
            free(node->data.function.name);
            for (int i = 0; i < node->data.function.param_count; i++) {
                free(node->data.function.params[i]);
            }
            free(node->data.function.params);
            free_ast(node->data.function.body);
            break;
            
        case AST_IF_STMT:
            free_ast(node->data.if_stmt.condition);
            free_ast(node->data.if_stmt.then_branch);
            free_ast(node->data.if_stmt.else_branch);
            break;
            
        case AST_BLOCK:
        case AST_PROGRAM:
            for (int i = 0; i < node->data.block.count; i++) {
                free_ast(node->data.block.statements[i]);
            }
            free(node->data.block.statements);
            break;
            
        case AST_FUNCTION_CALL:
            free(node->data.call.name);
            for (int i = 0; i < node->data.call.arg_count; i++) {
                free_ast(node->data.call.args[i]);
            }
            free(node->data.call.args);
            break;
    }
    
    free(node);
}

// Print AST for debugging
void print_ast(ASTNode *node, int indent) {
    if (!node) return;
    
    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (node->type) {
        case AST_PROGRAM:
            printf("PROGRAM\n");
            for (int i = 0; i < node->data.block.count; i++) {
                print_ast(node->data.block.statements[i], indent + 1);
            }
            break;
            
        case AST_FUNCTION_DECL:
            printf("FUNCTION: %s (", node->data.function.name);
            for (int i = 0; i < node->data.function.param_count; i++) {
                printf("%s%s", node->data.function.params[i], 
                       i < node->data.function.param_count - 1 ? ", " : "");
            }
            printf(")\n");
            print_ast(node->data.function.body, indent + 1);
            break;
            
        case AST_BLOCK:
            printf("BLOCK\n");
            for (int i = 0; i < node->data.block.count; i++) {
                print_ast(node->data.block.statements[i], indent + 1);
            }
            break;
            
        case AST_VAR_DECL:
            printf("VAR_DECL: %s\n", node->data.var_decl.name);
            if (node->data.var_decl.initializer) {
                print_ast(node->data.var_decl.initializer, indent + 1);
            }
            break;
            
        case AST_ASSIGNMENT:
            printf("ASSIGNMENT: %s\n", node->data.assignment.name);
            print_ast(node->data.assignment.value, indent + 1);
            break;
            
        case AST_BINARY_OP:
            printf("BINARY_OP: %s\n", node->data.binary.op);
            print_ast(node->data.binary.left, indent + 1);
            print_ast(node->data.binary.right, indent + 1);
            break;
            
        case AST_IDENTIFIER:
            printf("IDENTIFIER: %s\n", node->data.value);
            break;
            
        case AST_NUMBER:
            printf("NUMBER: %s\n", node->data.value);
            break;
            
        case AST_STRING:
            printf("STRING: %s\n", node->data.value);
            break;
            
        case AST_IF_STMT:
            printf("IF_STMT\n");
            for (int i = 0; i < indent + 1; i++) printf("  ");
            printf("condition:\n");
            print_ast(node->data.if_stmt.condition, indent + 2);
            for (int i = 0; i < indent + 1; i++) printf("  ");
            printf("then:\n");
            print_ast(node->data.if_stmt.then_branch, indent + 2);
            if (node->data.if_stmt.else_branch) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("else:\n");
                print_ast(node->data.if_stmt.else_branch, indent + 2);
            }
            break;
            
        case AST_FUNCTION_CALL:
            printf("CALL: %s (", node->data.call.name);
            for (int i = 0; i < node->data.call.arg_count; i++) {
                printf("%d%s", i, i < node->data.call.arg_count - 1 ? ", " : "");
            }
            printf(")\n");
            for (int i = 0; i < node->data.call.arg_count; i++) {
                print_ast(node->data.call.args[i], indent + 1);
            }
            break;
    }
}