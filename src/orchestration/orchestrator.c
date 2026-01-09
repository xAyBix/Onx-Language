#include <stdlib.h>
#include <stdio.h>
#include "orchestration/orchestrator.h"
#include "io/input.h"
#include "tokenizer/tokenizer.h"



void compile(CompilerConfig *compiler_config)
{
//     First read files
    char **contents = filesReader((const char**)compiler_config->source_files_paths, compiler_config->source_files_count);
    if (contents == NULL)
    {
        exit(1);
    }

//     Tokenization
    TokenList *token_lists = malloc(compiler_config->source_files_count * sizeof(TokenList));
    if (token_lists == NULL)
    {
        printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mFailed to allocate memory\n");
        exit(1);
    }
    for (int file_idx = 0; file_idx < compiler_config->source_files_count; file_idx++)
    {   
        init_token_list(&token_lists[file_idx]);
        tokenize(contents[file_idx], &token_lists[file_idx]);
    }
    
    // Print tokens grouped by file
    for (int file_idx = 0; file_idx < compiler_config->source_files_count; file_idx++)
    {
        printf("\n--- File: %s ---\n", compiler_config->source_files_paths[file_idx]);
        
        for (int i = 0; i < token_lists[file_idx].count; i++)
        {
            printf("  text: %-15s type: %-20s line: %d column: %d\n",
                   token_lists[file_idx].tokens[i].text,
                   token_lists[file_idx].tokens[i].type,
                   token_lists[file_idx].tokens[i].line,
                   token_lists[file_idx].tokens[i].column);
        }
    }


//      Parser
    




    // Free all token lists
    for (int file_idx = 0; file_idx < compiler_config->source_files_count; file_idx++)
    {
        free_token_list(&token_lists[file_idx]);
    }
    free(token_lists);

    // Free file contents
    for (int i = 0; i < compiler_config->source_files_count; i++)
    {
        free(contents[i]);
    }
    free(contents);
     
}

