// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "io/input.h"

char* fileReader (const char *path);
char** filesReader (const char **paths, const int count);
static int is_valid(const char *path);


char** filesReader(const char **paths, int count)
{
    if (paths == NULL || count <= 0)
    {
        return NULL;
    }
    
    // Allocate array of string pointers
    char **contents = (char**)malloc(count * sizeof(char*));
    if (contents == NULL)
    {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mFailed to allocate memory.\n\n");
        return NULL;
    }
    
    for (int i = 0; i < count; i++)
    {
        contents[i] = fileReader(paths[i]);
        
        if (contents[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(contents[j]);
            }
            free(contents);
            return NULL;
        }
    }
    
    return contents;
}


char* fileReader (const char *path)
{
    if (!is_valid(path))
    {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0m%s: Invalid file.\n\n", path);
        return NULL;
    }

    FILE *pSourceFile = fopen(path, "r");
    
    if (pSourceFile == NULL)
    {
        if (errno == 2) 
		{
			printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0m%s: No such file.\n\n", path);
		} else if (errno == 13)
		{
			printf("\033[38;5;208mOnx>> \x1b[31mError: %s: \x1b[0mPermission denied.\n\n", path);
		}else 
		{
			printf("\033[38;5;208mOnx>> \x1b[31mError: %s: \x1b[0mFailed to read.\n\n", path);
		}
        return NULL;
    }
    
    // Get file size
    fseek(pSourceFile, 0, SEEK_END);
    long size = ftell(pSourceFile);
    fseek(pSourceFile, 0, SEEK_SET);
    
    char *content = (char*)malloc(size + 1);
    if (content == NULL)
    {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mFailed to allocate memory.\n\n");
        fclose(pSourceFile);
        return NULL;
    }
    
    fread(content, 1, size, pSourceFile);
    content[size] = '\0';
    
    fclose(pSourceFile);
    return content;
}


static int is_valid(const char *path)
{
    if (path == NULL)
    {
        return 0;
    }
    
    size_t len = strlen(path);
    
    if (len < 4)
    {
        return 0;
    }
    
    return strcmp(path + len - 4, ".onx") == 0;
}