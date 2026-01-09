// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#include <stdlib.h>
#include <stdio.h>
#include "commands/version.h"

#define VERSION "0.0.1-SNAPSHOT"
#define CURRENT_YEAR "2026"



static void print_onx();



// A function that prints version
void print_version() 
{
	printf("\033[38;5;208mOnx\x1b[0mCompiler\t %s\n\n", VERSION);
	print_onx();
	printf("\n");
	printf("Copyright (C) %s Akram BELBEKRI.\n\n", CURRENT_YEAR);
}



// A function that prints Onx logo
static void print_onx() 
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