#include "main.h"

#define MAX_INPUT 1024
#define MAX_ARGS 100

/**
 * main -> entry point
 *
 * Return: Integer
 */

int main(void)
{
	char input[MAX_INPUT];
	char *args[MAX_ARGS];

	while (1)
	{
		printf("Emmy_shell$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;
		clean_input(input);

		if (strlen(input) == 0)
		{
			continue;
		}
		
		parse_input(input, args);

		if (strcmp(args[0], "exit") == 0)
			break;
		
		handle_builtin_commands(args);
	}
		
		printf("Goodbye!\n");
		return (0);
}
