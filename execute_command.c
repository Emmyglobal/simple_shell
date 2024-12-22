#include "main.h"

/**
 * execute_command -> execute commands entered by the user
 * @args: argument passed
 *
 * Return: Nothing
 */

void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("myshell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("myshell");
	else
		waitpid(pid, NULL, 0);
}
