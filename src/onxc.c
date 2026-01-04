#include <stdlib.h>
#include <stdio.h>
#include <errno.h> 

int main (int argc, char *argv[]) 
{
	// Handling arguments exceptions
	if (argc < 2) 
	{
		printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mExpected \"%s <source file> <target file>\".\n\033[38;5;208mOnx>> \x1b[32mHint: \x1b[0mUse \"%s -h\" to learn more.\n\n",
			argv[0], argv[0]);
		return 1;
	}
	
	FILE *pSourceFile = fopen(argv[1], "r");
	// Handling file exception
	if (pSourceFile == NULL) 
	{
		if (errno == 2) 
		{
			printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0m%s: No such file.\n\n", argv[1]);
		} else if (errno == 13)
		{
			printf("\033[38;5;208mOnx>> \x1b[31mError: %s: \x1b[0mPermission denied.\n\n", argv[1]);
		}else 
		{
			printf("\033[38;5;208mOnx>> \x1b[31mError: %s: \x1b[0mFailed to read.\n\n", argv[1]);
		}
		return 1;
	}



	return 0;

}
