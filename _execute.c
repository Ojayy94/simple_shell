#include "shell.h"

/**
 * execute_command - Program to execute a command
 * @command: Command function
 * Return: Prompt
 */

int execute_command(char *command)
{
	pid_t child_pid;
	int status;
	char **argv;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		return (-1);
	}

	if (child_pid == 0)
	{
		argv = (char **)malloc(2 * sizeof(char *));
		if (argv == NULL)
		{
			perror("Error");
			_exit(EXIT_FAILURE);
		}
		argv[0] = command;
		argv[1] = NULL;

		execve(command, argv, NULL);

		perror("Error (execve)");
		free(argv);
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (0);
		}
		else
		{
			return (-1);
		}
	}
}
