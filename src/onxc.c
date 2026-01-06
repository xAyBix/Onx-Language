#include <stdlib.h>
#include "commands/commands_manager.h"




int main (int argc, char *argv[]) 
{

	return check_for_command_errors(argc, argv);

	// FILE *pSourceFile = fopen(argv[1], "r");
	// // Handling file exception
	// if (pSourceFile == NULL) 
	// {
	// 	if (errno == 2) 
	// 	{
	// 		printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0m%s: No such file.\n\n", argv[1]);
	// 	} else if (errno == 13)
	// 	{
	// 		printf("\033[38;5;208mOnx>> \x1b[31mError: %s: \x1b[0mPermission denied.\n\n", argv[1]);
	// 	}else 
	// 	{
	// 		printf("\033[38;5;208mOnx>> \x1b[31mError: %s: \x1b[0mFailed to read.\n\n", argv[1]);
	// 	}
	// 	return 1;
	// }

}
