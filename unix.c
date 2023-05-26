#include "shell.h"


int main()
{
	char input[MAX_INPUT_LENGTH];
	char *args[2];
	int status;

	while (1)
	{
		printf("EMMYtech");
		fflush(stdout);

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("n");
			break;
		}

		input[strcspn(input, "n")] = '0';/* Removing trailing newline*/

		args[0] = input;
		args[1] = NULL;

		pid_t expid = fork();

		if (expid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (expid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(expid, &status, 0);
		}
	}

	return (0);
}
