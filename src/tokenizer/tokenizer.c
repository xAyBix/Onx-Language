#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "tokenizer/tokenizer.h"


Token** tokenizer (const char **contents, int count);
static char* patterns_join(const char *separator, int count, ...);


Token** tokenizer (const char **contents, int count)
{
    char *patterns = patterns_join("|", 47, 
        "(?<NUMBER>\\d+(\\.\\d+)?)", 
        "(?<STARTFUNC>start(\\s)*?\\(args\\))", 

        //Comments
        "(?<COMMENT>//.*?)(?=\r?\n|$)",
        "(?<MULTILINECOMMENT>/\\*[\\s\\S]*?\\*/)", 

        "(?<LET>let)",
        "(?<PRINTFUNC>print)",

        //Conditions statements
        "(?<IF>if)", 
        "(?<ELSE>else)",
        "(?<SWITCH>switch)",
        "(?<CASE>case)",
        "(?<DEFAULT>default)",

        //Boolean
        "(?<TRUE>true)",
        "(?<FALSE>false)",

        //Loops
        "(?<FOR>for)", 
        "(?<WHILE>while)",
        "(?<DO>do)", 
        "(?<BREAK>break)", 
        "(?<CONTINUE>continue)", 

        //Operators
        "(?<PLUS>\\+)",    
        "(?<MINUS>-)",     
        "(?<MULTIPLY>\\*)",
        "(?<DIVIDE>/)(?!\\*)",    
        "(?<MODULO>%)",
        "(?<EQUALS>==)",    
        "(?<NOTEQUAL>!=)",    
        "(?<GREATER>>)",     
        "(?<LESS><)",        
        "(?<GREATEREQUAL>>=)",    
        "(?<LESSEQUAL><=)",      
        "(?<AND>&&)",          
        "(?<OR>\\|\\|)",       
        "(?<NOT>!)",

        "(?<RETURN>return)",
        "(?<NULL>null)",
        "(?<ASSIGN>=)",
        "(?<COLON>:)",
        "(?<COMMA>,)",
        "(?<STRING>\"[^\"]*\")", 
        "(?<CHAR>'[^']*')", 
        "(?<IDENTIFIER>[a-zA-Z_]\\w*)",
        "(?<LBRACE>\\{)", 
        "(?<RBRACE>\\})", 
        "(?<LPAREN>\\()", 
        "(?<RPAREN>\\))",
        "(?<NEWLINE>\\n)",
        "(?<SEMICOLON>;)", 
        "(?<WHITESPACE>\\s+)");

    return NULL;
}



static char* patterns_join(const char *separator, int count, ...)
{
    va_list args;
    va_start(args, count);
    
    // Calculate total length
    size_t sep_len = strlen(separator);
    size_t total_len = 0;
    
    // First pass: calculate length
    va_list args_copy;
    va_copy(args_copy, args);
    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args_copy, const char*);
        total_len += strlen(str);
        if (i < count - 1)
        {
            total_len += sep_len;
        }
    }
    va_end(args_copy);
    
    // Allocate memory
    char *result = (char*)malloc(total_len + 1);
    if (result == NULL)
    {
        va_end(args);
        return NULL;
    }
    
    // Second pass: build string
    char *ptr = result;
    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args, const char*);
        size_t len = strlen(str);
        memcpy(ptr, str, len);
        ptr += len;
        
        if (i < count - 1)
        {
            memcpy(ptr, separator, sep_len);
            ptr += sep_len;
        }
    }
    *ptr = '\0';
    
    va_end(args);
    return result;
}