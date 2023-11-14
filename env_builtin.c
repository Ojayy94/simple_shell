#include "shell.h"

void env_shell()
{
        char **env;

        for (env = environ; *env != NULL; env++)
        {
                printf("%s\n", *env);
        }
}
