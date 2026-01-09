// Onx Language
// Copyright (C) 2026 Akram BELBEKRI
// Original creator of the language
// Licensed under GNU GPL v3

#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

typedef struct {
    char *output_file;
    char **source_files_paths;
    int source_files_count;
    int compile_only;
}CompilerConfig;

void compile (CompilerConfig *compiler_config);

#endif
