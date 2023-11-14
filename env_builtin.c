#include "shell.h"
/**
 * env_shell - get shell environment variable
 * Return: env
 */
void env_shell(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
