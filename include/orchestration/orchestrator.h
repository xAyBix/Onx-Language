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
