#include "shell.h"

/**
 * tokenize_input - Tokenise input function
 * @input: input to tokenise
 * Return: success
 */

char **tokenize_input(char *input)
{
	char *token = strtok(input, " ");
	int arg_count = 0;
	char **args = (char **)malloc(MAX_INPUT_SIZE * sizeof(char *));

	if (args == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		args[arg_count] = strdup(token);

		if (args[arg_count] == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	return (args);
}
