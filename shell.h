#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_SIZE 100

extern char **environ;

void execute_command(char *command);
void execute_command_with_args(char *command, char **args);
void execute_command_with_path(char *command, char **args);
void exit_shell();
void env_shell();
char **tokenize_input(char *input);
void handle_command_line_with_args(int argc, char *argv[]);


#endif /* SHELL_H */
