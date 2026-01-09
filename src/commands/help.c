// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#include <stdio.h>
#include "commands/help.h"

void print_help(char *program) 
{
    printf("\033[38;5;208mOnx\x1b[0mCompiler - A compiler for Onx Language\n\n");
    
    printf("USAGE:\n");
    printf("    %s [OPTIONS] [FILES...]\n\n", program);
    
    printf("OPTIONS:\n");
    printf("    -h, --help                  Show this help menu\n");
    printf("    -v, --version               Display compiler version\n\n");
    
    printf("    -c, --compile <files...>    Compile source files and check for errors\n");
    printf("                                Does not produce executable output\n");
    printf("                                Example: %s -c main.onx utils.onx\n\n", program);
    
    printf("    -b, --build [target] <files...>\n");
    printf("                                Build source files into executable\n");
    printf("                                Target file is optional (defaults to 'a.out')\n");
    printf("                                Example: %s -b output main.onx\n", program);
    printf("                                Example: %s -b main.onx utils.onx\n\n", program);
    
    printf("EXAMPLES:\n");
    printf("    %s --version\n", program);
    printf("        Display the current version of OnxCompiler\n\n");
    
    printf("    %s --compile main.onx\n", program);
    printf("        Check main.onx for compilation errors\n\n");
    
    printf("    %s --compile src/main.onx src/helper.onx\n", program);
    printf("        Check multiple files for errors\n\n");
    
    printf("    %s --build program main.onx utils.onx\n", program);
    printf("        Build executable named 'program' from source files\n\n");
    
    printf("    %s --build main.onx utils.onx\n", program);
    printf("        Build executable with default name from source files\n\n");
    
    printf("For more information, visit: https://github.com/xAyBix/Onx-Language\n");
    printf("Report bugs at: https://github.com/xAyBix/Onx-Language/issues\n");
}