#include <stdlib.h>
#include <stdio.h>
#include "orchestration/orchestrator.h"
#include "io/input.h"



void compile(CompilerConfig *compiler_config)
{
    // First read files
     char **contents = filesReader((const char**)compiler_config->source_files_paths, compiler_config->source_files_count);
     if (contents == NULL)
     {
        exit(1);
     }

     // Tokenization
     
}

