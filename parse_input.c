#include "main.h"

#define MAX_ARGS 100
/**
 * parse_input -> Tokenize by space
 * @input: input to be tokenizi
 * @args: arguments
 */

void parse_input(char *input, char **args)
{
	int i = 0 ;
	char *token = strtok(input, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
