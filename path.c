#include "shell.h"
/**
 * execute_command_with_path - path execution
 * @command: command function
 * @args: argument string
 * Return: path
 */
void execute_command_with_path(char *command, char **args)
{
	pid_t pid;
	int status;

	if (!command)
	{
		fprintf(stderr, "Invalid command\n");
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
