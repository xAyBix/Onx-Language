// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#ifndef MATCHER_H
#define MATCHER_H

int matchKeyword(const char *input, const char *keyword, int *length);
int matchNumber(const char *input, int *length);
int matchIdentifier(const char *input, int *length);
int matchString(const char *input, int *length, int *lines, char **error);
int matchComment(const char *input, int *length);
int matchMultiLineComment(const char *input, int *length, int *lines, char **error);
#endif