#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

void clean_input(char *input);
void parse_input(char *input, char **args);
void execute_command(char **args);
void handle_builtin_commands(char **args);

#endif
