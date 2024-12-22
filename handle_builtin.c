#include "main.h"

/**
 * handle_builtin_commands -> handles change directory
 * @args: argument
 *
 * Return: Nothing
 */

void handle_builtin_commands(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			const char *home = getenv("HOME");
			if (home == NULL)
				fprintf(stderr, "myshell: HOME not set\n");
			else if (chdir(home) != 0)
				perror("myshell");
		}
		else
		{
			if (chdir(args[1]) != 0)
				perror("myshell");
		}
	}
	else
	{
		execute_command(args);
	}
}
