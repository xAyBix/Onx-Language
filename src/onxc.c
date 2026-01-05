#include <stdlib.h>
#include <stdio.h>
#include <errno.h> 
#include <string.h>

#define VERSION "0.0.1-SNAPSHOT"

// A function that prints error if arguments less than 2
void print_less_than_two_error(char *argv);
// A function that prints Onx logo
void print_onx();
// A function that prints help menu
void print_help();
// A function that prints version
void print_version();

int main (int argc, char *argv[]) 
{
	// Handling arguments exceptions
	if (argc < 2) 
	{
		print_less_than_two_error(argv[0]);	
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
			printf("Copyright (C) 2026 Akram BELBEKRI.\n\n");
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

void print_less_than_two_error(char *argv) 
{
	printf("\033[38;5;208mOnx>> \x1b[31mError: \x1b[0mExpected \"%s <source file> <target file>\".\n\033[38;5;208mOnx>> \x1b[32mHint: \x1b[0mTry \"%s -h\" to learn more.\n\n",
			argv, argv);

}



void print_onx() 
{
    // Color codes for orange gradient (light to dark)
    const char *colors[] = {
        "\033[38;2;255;200;120m",
        "\033[38;2;255;180;100m",
        "\033[38;2;255;160;80m",
        "\033[38;2;255;140;60m",
        "\033[38;2;255;120;40m",
        "\033[38;2;255;100;30m",
        "\033[38;2;240;90;25m",
        "\033[38;2;230;80;20m",
        "\033[38;2;220;70;15m",
        "\033[38;2;210;60;10m",
        "\033[38;2;200;50;10m",
        "\033[38;2;190;45;8m",
        "\033[38;2;180;40;5m",
        "\033[38;2;170;35;5m",
        "\033[38;2;160;30;3m",
        "\033[38;2;150;25;2m",
        "\033[38;2;140;20;0m",
        "\033[38;2;130;15;0m"
    };
    const char *reset = "\033[0m";

    printf("%s                r             o%s\n", colors[0], reset);
    printf("%s           rfftt\\             1%s\n", colors[1], reset);
    printf("%s      xrrrjjxrt              r\\%s\n", colors[2], reset);
    printf("%s    nnn   cjjj              rt/%s\n", colors[3], reset);
    printf("%s  vuuu ONX rrr         cxxrjjj%s\n", colors[4], reset);
    printf("%s           Yxx|       vunnxxrr%s\n", colors[5], reset);
    printf("%s          nxxx      zcvvuunxr%s\n", colors[6], reset);
    printf("%s       vvuunr   JUXXXzccvvn    n%s\n", colors[7], reset);
    printf("%s    Czzcc vv  OLCCJLXY      vvuu%s\n", colors[8], reset);
    printf("%s  UXXz UvC  0          Uzzzccv%s\n", colors[9], reset);
    printf("%s YYY Czcc  mQ0QQLCJJJUYYXzzc%s\n", colors[10], reset);
    printf("%sJYY  XznJx   O00QLLCCJUUJ%s\n", colors[11], reset);
    printf("%swUX  CYv Czzx              xr|%s\n", colors[12], reset);
    printf("%s JUJ YYYr  Uzcz         unxx%s\n", colors[13], reset);
    printf("%s  LJJX  YY    Yzzccvvvvuuc   X%s\n", colors[14], reset);
    printf("%s   0JJ   qYYc              un%s\n", colors[15], reset);
    printf("%s      OJJY     UCXXUYzccc%s\n", colors[16], reset);
    printf("%s         LJJJYUYYYXXzz%s\n", colors[17], reset);
}
