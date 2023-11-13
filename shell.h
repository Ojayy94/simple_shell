#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define INPUT_SIZE 100

extern char **environ;

#define PROMPT "$ "

int main(void);
int execute_command(char *command);


#endif /* SHELL_H */
