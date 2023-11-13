#include "shell.h"

/**
 * main - Display prompt
 * Return: Success
 */

int main(void)
{
	char input[INPUT_SIZE];
	char *prompt = "$ ";
	char *line = NULL;
	size_t num = 0;
	ssize_t buff;

	while (1)
	{
		write(1, prompt, 3);

		buff = getline(&line, &num, stdin);
		if (buff != EOF)
		{
			write(1, line, strlen(line));
			write(1, prompt, 3);
		}
		if (buff == -1)
		{
			perror("Error");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (line[buff - 1] == '\n')
			line[buff - 1] = 0;

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		exec(input);
	}
	free(line);
	return (0);
}
