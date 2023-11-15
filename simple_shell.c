#include "shell.h"

/**
 * run_shell - main function that runs the command
 * Return: Success
 */

int run_shell(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t n;
	int i, is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			printf("$ "), fflush(stdout);
		n = getline(&input, &input_size, stdin);
		if (n == -1)
		{
			if (is_interactive)
				printf("\n");
			free(input);
			return (0);
		}
		if (n > 0)
			input[n - 1] = '\0';
		if (strcmp(input, "exit") == 0)
			free(input), return (0);
		else if (strcmp(input, "env") == 0)
			env_shell();
		else
		{
			char *command = strtok(input, " "), **args = tokenize_input(input);

			if (access(command, X_OK) == 0)
				execute_command_with_path(command, args);
			else
				fprintf(stderr, "Command not found: %s\n", command);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
		if (!is_interactive)
			break;
	}
	free(input);
	return (1);
}

/**
 * main - function that runs shell
 * Return: Success
 */

int main(void)
{
	while (run_shell())
	{}
	return (0);
}
