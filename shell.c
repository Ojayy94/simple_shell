#include "shell.h"

/**
 * main - main function to execute command
 * Return: function
 */

int main(void)
{
	char *line = NULL;
	size_t last_char, len = 0;
	ssize_t read;
	char *command;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
				if (is_interactive)
				{
					printf("\n");
				}
				free(line), exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error"), free(line), exit(EXIT_FAILURE);
			}
		}
		last_char = read - 1;
		if (line[last_char] == '\n')
			line[last_char] = '\0';
		command = strtok(line, "\"");
		if (command == NULL)
			continue;
		if (is_interactive || command[0] != '\0')
		{
			if (execute_command(command) == -1)
				perror("Error");
		}
	}
	return (0);
}
