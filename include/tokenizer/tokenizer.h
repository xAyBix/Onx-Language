// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef struct {
    char *text;
    char *type;
    int line;
    int column;
}Token;

typedef struct {
    Token *tokens;
    size_t count;
    size_t capacity;
}TokenList;

void tokenize (const char *content, TokenList *token_list);
void init_token_list (TokenList *token_list);
void add_token_to_token_list (TokenList *token_list, const char *text, const char *type, int line, int column);
void free_token_list (TokenList *token_list);

#endif