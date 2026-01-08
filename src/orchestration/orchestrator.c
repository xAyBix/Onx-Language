#include <stdlib.h>
#include <stdio.h>
#include "orchestration/orchestrator.h"
#include "io/input.h"
#include "tokenizer/tokenizer.h"



void compile(CompilerConfig *compiler_config)
{
    // First read files
     char **contents = filesReader((const char**)compiler_config->source_files_paths, compiler_config->source_files_count);
     if (contents == NULL)
     {
        exit(1);
     }

     // Tokenization
     TokenList token_list;
     init_token_list(&token_list);
     tokenize(contents[0], &token_list); // Works only for one file for the moment
}

