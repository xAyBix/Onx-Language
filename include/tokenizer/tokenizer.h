#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum {
    // Literals
    NUMBER, STRING, CHARACTER, NULLTOKEN, TRUE, FALSE,
    
    // Keywords
    STARTFUNC, PRINTFUNC, INPUTFUNC, LET, RETURN, IF, ELSE, WHILE, FOR,
    
    // Operators
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO, ASSIGN,
    EQUALS, NOTEQUAL, LESS, GREATER, LESSEQUAL, GREATEREQUAL,
    NOT, OR, AND,
    
    // Delimiters
    LPARENT, RPARENT, LBRACE, RBRACE, LBRACKET, RBRACKET,
    COMMA, SEMICOLON, DOT,
    
    // Special
    IDENTIFIER, COMMENT, MULTILINECOMMENT, NEWLINE, WHITESPACE, ENDOFFILE
}TokenTypes;

typedef struct {
    char *text;
    TokenTypes token_type;
    int line;
    int column;
}Token;

Token** tokenize (const char **contents, int count);

#endif