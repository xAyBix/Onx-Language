#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands/commands_manager.h"
#include "commands/version.h"
#include "commands/help.h"


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
//			compile_handler();

		}else if (strcmp(argv[1], "--build") == 0 || strcmp(argv[1], "-b") == 0)// Build
		{
//			build_handler();
		}else// Invalid
		{
			
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
