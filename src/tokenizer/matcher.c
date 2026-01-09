#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer/matcher.h"


int matchKeyword(const char *input, const char *keyword, int *length);
int matchNumber(const char *input, int *length);
int matchIdentifier(const char *input, int *length);
int matchString(const char *input, int *length, int *lines, char **error);
int matchComment(const char *input, int *length);
int matchMultiLineComment(const char *input, int *length, int *lines, char **error);



int matchKeyword(const char *input, const char *keyword, int *length) 
{
    *length = strlen(keyword);
    
    if (strncmp(input, keyword, *length) != 0) {
        return 0;
    }
    
    char next_char = input[*length];
    if (isalnum(next_char) || next_char == '_') {
        return 0;  
    }
    
    return 1;
}

int matchNumber(const char *input, int *length) 
{
    *length = 0;
    while (isdigit(input[*length])) (*length)++;
    return *length > 0;
}

int matchIdentifier(const char *input, int *length) 
{
    *length = 0;
    if (isalpha(input[0]) || input[0] == '_') 
    {
        (*length)++;
        while (isalnum(input[*length]) || input[*length] == '_') 
        {
            (*length)++;
        }
        return 1;
    }
    return 0;
}

int matchString(const char *input, int *length, int *lines, char **error) 
{
    *length = 0;
    *lines = 0;
    *error = NULL;
    
    if (input[0] != '"' && input[0] != '\'') {
        return 0;
    }
    
    char quote = input[0];
    (*length)++;
    
    while (input[*length] != '\0') {
        // Handle escape sequences
        if (input[*length] == '\\') 
        {
            (*length)++;
            if (input[*length] == '\0') 
            {
                *error = "Unterminated string: unexpected end of input after escape";
                return 0;
            }
            (*length)++;
            continue;
        }
        
        // Track newlines in string
        if (input[*length] == '\n') 
        {
            (*lines)++;
        }
        
        // Found closing quote
        if (input[*length] == quote) 
        {
            (*length)++;
            return 1;
        }
        
        (*length)++;
    }
    
    *error = "Unterminated string: reached end of input";
    return 0;
}

// Match single-line comments (// style)
int matchComment(const char *input, int *length) 
{
    *length = 0;
    
    // Check for // comment
    if (input[0] == '/' && input[1] == '/') 
    {
        *length = 2;
        while (input[*length] != '\0' && input[*length] != '\n') 
        {
            (*length)++;
        }
        return 1;
    }
    
    return 0;
}

// Match multi-line comments (/* */ style)
int matchMultiLineComment(const char *input, int *length, int *lines, char **error) 
{
    *length = 0;
    *lines = 0;
    *error = NULL;
    
    if (input[0] != '/' || input[1] != '*') 
    {
        return 0;
    }
    
    *length = 2;
    
    while (input[*length] != '\0') 
    {
        if (input[*length] == '\n') 
        {
            (*lines)++;
        }
        
        // Found closing */
        if (input[*length] == '*' && input[*length + 1] == '/') 
        {
            *length += 2;
            return 1;
        }
        
        (*length)++;
    }
    
    *error = "Unterminated multi-line comment: reached end of input";
    return 0;
}