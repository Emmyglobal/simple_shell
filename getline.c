#include <stdio.h>
#include <stdlib.h>

int main()
{
	size_t n = 30;

	char *buffer = malloc(sizeof(char) * n);

	printf("EmmyTech ");

	while (getline(&buffer, &n, stdin) != -1)
	{
		printf("%s", buffer);
		printf("EmmyTech ");
	}

	free(buffer);

	return (0);
}
