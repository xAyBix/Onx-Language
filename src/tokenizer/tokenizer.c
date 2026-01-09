// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/matcher.h"


void tokenize (const char *content, TokenList *token_list);
void init_token_list (TokenList *token_list);
void add_token_to_token_list (TokenList *token_list, const char *text, const char *type, int line, int column);
void free_token_list (TokenList *token_list);




void tokenize (const char *content, TokenList *token_list)
{
    int line_number = 1;
    int column_number = 1;
    int i = 0;
    int len = strlen(content);
    
    while (i < len) {
        int match_len = 0;
        int extra_lines = 0;
        char *error = NULL;
        
        // Skip whitespace
        if (content[i] == ' ' || content[i] == '\t' || content[i] == '\r') {
            if (content[i] == '\t') {
                column_number += 4;
            } else {
                column_number++;
            }
            i++;
            continue;
        }
        
        // Handle newline
        if (content[i] == '\n') {
            line_number++;
            column_number = 1;
            i++;
            continue;
        }
        // Match multi-line comments (check before single-line comments)
        if (matchMultiLineComment(&content[i], &match_len, &extra_lines, &error)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "MULTILINE_COMMENT", line_number, column_number);
            free(text);
            i += match_len;
            line_number += extra_lines;
            if (extra_lines > 0) {
                // Calculate column after last newline in comment
                int lastNewline = i - 1;
                while (lastNewline > 0 && content[lastNewline] != '\n') {
                    lastNewline--;
                }
                column_number = (lastNewline > 0) ? (i - lastNewline) : (column_number + match_len);
            } else {
                column_number += match_len;
            }
        }
        // Match single-line comments
        else if (matchComment(&content[i], &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "COMMENT", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        // Match strings
        else if (matchString(&content[i], &match_len, &extra_lines, &error)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "STRING", line_number, column_number);
            free(text);
            i += match_len;
            line_number += extra_lines;
            if (extra_lines > 0) {
                // Calculate column after last newline in string
                int lastNewline = i - 1;
                while (lastNewline > 0 && content[lastNewline] != '\n') {
                    lastNewline--;
                }
                column_number = (lastNewline > 0) ? (i - lastNewline) : (column_number + match_len);
            } else {
                column_number += match_len;
            }
        }
        // Match keywords
        else if (matchKeyword(&content[i], "start", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "STARTFUNC", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "use", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "USE", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "print", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "PRINTFUNC", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "args", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "KEYWORD", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "let", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "KEYWORD", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "if", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "KEYWORD", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "else", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "KEYWORD", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        // Match numbers
        else if (matchNumber(&content[i], &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "NUMBER", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        // Match identifiers
        else if (matchIdentifier(&content[i], &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "IDENTIFIER", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        // Match operators and punctuation
        else if (matchKeyword(&content[i], "===", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "STRICTEQUALS", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "==", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "EQUALS", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], ">=", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "GREATEREQUAL", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "<=", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "LOWEREQUAL", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], ">=", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "GREATEREQUALS", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], ">", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "GREATER", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "<", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "LOWER", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "||", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "OR", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "&&", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "AND", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (matchKeyword(&content[i], "=", &match_len)) {
            char *text = strndup(&content[i], match_len);
            add_token_to_token_list(token_list, text, "ASSIGNMENT", line_number, column_number);
            free(text);
            i += match_len;
            column_number += match_len;
        }
        else if (content[i] == ';') {
            add_token_to_token_list(token_list, ";", "SEMICOLON", line_number, column_number);
            i++;
            column_number++;
        }
        else if (content[i] == '+') {
            add_token_to_token_list(token_list, "+", "OPERATOR", line_number, column_number);
            i++;
            column_number++;
        }
        else if (content[i] == '-') {
            add_token_to_token_list(token_list, "-", "OPERATOR", line_number, column_number);
            i++;
            column_number++;
        }
        else if (content[i] == '(') {
            add_token_to_token_list(token_list, "(", "LPAREN", line_number, column_number);
            i++;
            column_number++;
        }
        else if (content[i] == ')') {
            add_token_to_token_list(token_list, ")", "RPAREN", line_number, column_number);
            i++;
            column_number++;
        }
        else if (content[i] == '{') {
            add_token_to_token_list(token_list, "{", "LBRACE", line_number, column_number);
            i++;
            column_number++;
        }
        else if (content[i] == '}') {
            add_token_to_token_list(token_list, "}", "RPAREN", line_number, column_number);
            i++;
            column_number++;
        }
        // Unknown character
        else {
            printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mUnknown character '%c' at line %d, column %d\n", 
                    content[i], line_number, column_number);
            // i++;
            // column_number++;
            exit(0);
        }

        if (error) {
            printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mAt line %d, column %d: %s\n", line_number, column_number, error);
            exit(1);
        }
    }

}

void init_token_list (TokenList *token_list)
{
    token_list->count=0;
    token_list->capacity=10;
    token_list->tokens = malloc(token_list->capacity * sizeof(Token));
}

void add_token_to_token_list (TokenList *token_list, const char *text, const char *type, int line, int column)
{
    if (token_list->count >= token_list->capacity) {
        token_list->capacity *= 2;
        token_list->tokens = realloc(token_list->tokens, token_list->capacity * sizeof(Token));
    }
    
    token_list->tokens[token_list->count].text = strdup(text);
    token_list->tokens[token_list->count].type = strdup(type);
    token_list->tokens[token_list->count].line = line;
    token_list->tokens[token_list->count].column = column;
    token_list->count++;

}

void free_token_list (TokenList *token_list)
{
    for (size_t i = 0; i < token_list->count; i++) {
        free(token_list->tokens[i].text);
        free(token_list->tokens[i].type);
    }
    free(token_list->tokens);
}
