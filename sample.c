#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t expid, w;
	int wstatus;

	expid = fork();
	if (expid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (expid == 0)
	{
		printf("Child pid: %d\n", getpid());
		if (argc == 1)
		{
			pause();
			_exit(atoi(argv[1]));
		}
		else
		{
			do
			{
				w = waitpid(expid, &wstatus, WUNTRACED || WCONTINUED);
				if (w == -1)
				{
					perror("waitpid");
					exit(EXIT_FAILURE);
				}

				if (WIFEXITED(wstatus))
				{
					printf("Exited and the status");
				}
				else if (WIFSIGNALED(wstatus))
				{
					printf("Terminated");
				}
				else if (WIFSTOPPED(wstatus))
					printf("Stopped\n");
				else if (WIFCONTINUED(wstatus))
					printf("Continued\n");
			}
			while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
