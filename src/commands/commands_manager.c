// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands/commands_manager.h"
#include "commands/version.h"
#include "commands/help.h"
#include "commands/easter_eggs.h"
#include "orchestration/orchestrator.h"


static void print_less_than_two_error(const char *argv0);
static void print_invalid_option_error(char *argv[]);


int check_for_command_errors (int argc, char *argv[])
{
	// Handling arguments exceptions
	if (argc < 2) 
	{
		print_less_than_two_error(argv[0]);	
		return 1;
	}

	// Handling 2 arguments
	if (argc == 2) 
	{
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)// Help Menu
		{
			print_help(argv[0]);

		}else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)// Version Menu
		{

			print_version();	

		}else if (strcmp(argv[1], "--make-me-a-sandwich") == 0)
		{
			
			make_sandwich();

		}else// Invalid
		{

			print_invalid_option_error(argv);
			return 1;

		}

		return 0;
	}

	// Handling multiple arguments
	if (argc > 2)
	{
		if (strcmp(argv[1], "--compile") == 0 || strcmp(argv[1], "-c") == 0)// Compile
		{
			if (argc == 3 && strcmp(argv[2], "hello_world.onx") == 0)
			{
				hello_world();
			}
			else if (argc == 3 && strcmp(argv[2], "upside_down.onx") == 0)
			{
				upside_down();
			}

			CompilerConfig compiler_config;
			compiler_config.output_file = NULL;
			compiler_config.source_files_count = argc-2;
			// Allocate memory
    		compiler_config.source_files_paths = malloc(compiler_config.source_files_count * sizeof(char*));
    		if (compiler_config.source_files_paths == NULL) {
        		printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mFailed to allocate memory\n");
        		exit(1);
    		}
    
    		for (int i = 0; i < argc - 2; i++) 
    		{
        		compiler_config.source_files_paths[i] = strdup(argv[i + 2]);
        		if (compiler_config.source_files_paths[i] == NULL) {
            		printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mStrdup failed for argument %d\n", i);
            		// Free previously allocated strings
            		for (int j = 0; j < i; j++) {
                		free(compiler_config.source_files_paths[j]);
            		}
            		free(compiler_config.source_files_paths);
            		return 1;
       	 		}
    		}
    
    		compiler_config.compile_only = 1;
    		compile(&compiler_config);
    
    		// Free memory
    		for (int i = 0; i < compiler_config.source_files_count; i++) {
        		free(compiler_config.source_files_paths[i]);
    		}
    		free(compiler_config.source_files_paths);

		}else if (strcmp(argv[1], "--build") == 0 || strcmp(argv[1], "-b") == 0)// Build
		{
//			build_handler();
		}else// Invalid
		{
			print_invalid_option_error(argv);
		}
	}
	return 0;
} 

// A function that prints error if arguments less than 2
static void print_less_than_two_error(const char *argv0)
{
	printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mExpected \"%s [OPTIONS] [FILES...]\".\n\033[38;5;208mOnx>> \x1b[32mHint: \x1b[0mTry \"%s -h\" to learn more.\n\n",
			argv0, argv0);

}
// A function that prints error if the option is wrong
static void print_invalid_option_error(char *argv[])
{
	printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mInvalid option \"%s\"\n", argv[1]);
	printf("\033[38;5;208mOnx>> \x1b[32mHint: \x1b[0mTry \"%s -h\" for more information.\n\n", argv[0]);

}
