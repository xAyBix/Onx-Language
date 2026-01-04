#include <stdlib.h>
#include <stdio.h>
#include <errno.h> 
#include <string.h>

#define VERSION "0.0.1-SNAPSHOT"

void print_onx();

int main (int argc, char *argv[]) 
{
	// Handling arguments exceptions
	if (argc < 2) 
	{
		printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mExpected \"%s <source file> <target file>\".\n\033[38;5;208mOnx>> \x1b[32mHint: \x1b[0mTry \"%s -h\" to learn more.\n\n",
			argv[0], argv[0]);
		return 1;
	}

	// Handling options
	if (argc == 2) 
	{
		if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0)// Help Menu
		{
			printf("\n");

		}else if (strcmp(argv[1], "version") == 0 || strcmp(argv[1], "-v") == 0)
		{
			printf("\033[38;5;208mOnx\x1b[0mCompiler\t %s\n\n", VERSION);
			print_onx();
			printf("\n");
			printf("Copyright (c) 2026 Akram BELBEKRI.\n\n");
		}else
		{
			printf("\033[38;5;208mOnx>> \x1b[0mInvalid option \"%s\"\n", argv[1]);
			printf("\033[38;5;208mOnx>> \x1b[32mHint: \x1b[0mTry \"%s -h\" for more information.\n\n", argv[0]);
			return 1;
		}

		return 0;
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

void print_onx() {
	printf("\033[38;5;208m");
    printf("                 r             o\n");
    printf("           rfftt\\             1\n");
    printf("      xrrrjjxrt              r\\\n");
    printf("    nnn   cjjj              rt/\n");
    printf("  vuuu ONX rrr         cxxrjjj\n");
    printf("           Yxx|       vunnxxrr\n");
    printf("          nxxx      zcvvuunxr\n");
    printf("       vvuunr   JUXXXzccvvn    n\n");
    printf("    Czzcc vv  OLCCJLXY      vvuu\n");
    printf("  UXXz UvC  0          Uzzzccv\n");
    printf(" YYY Czcc  mQ0QQLCJJJUYYXzzc\n");
    printf("JYY  XznJx   O00QLLCCJUUJ\n");
    printf("wUX  CYv Czzx              xr|\n");
    printf(" JUJ YYYr  Uzcz         unxx\n");
    printf("  LJJX  YY    Yzzccvvvvuuc   X\n");
    printf("   0JJ   qYYc              un\n");
    printf("      OJJY     UCXXUYzccc\n");
    printf("         LJJJYUYYYXXzz\n");
	printf("\x1b[0m");
}
