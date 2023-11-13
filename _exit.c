#include "shell.h"

/**
 * _exit - main function to execute command
 * Return: function
 */

int my_exit(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		execute_command(input);
	}
	return (0);
}
