#include <stdio.h>
#include <stdlib.h>

/*
 * main -> A function of a simple shell
 * @ac: argument count
 * @av: argument vector
 */

int main(int ac, char *av[])
{
	char *command = NULL;
	size_t len = 0;

	printf("%i\n", ac);
	printf("%s", av[0]);

	while (1)
	{
		printf("EMMYTECH ");
		getline(&command, &len, stdin);
		printf("%s", command);
	}

	free(command);
	return (0);
}
