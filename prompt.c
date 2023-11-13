#include "shell.h"

/**
 * prompt - shell init prompt
 * return: prompt
 */

void prompt(void)
{
	write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
}

