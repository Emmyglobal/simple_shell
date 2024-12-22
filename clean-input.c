#include "main.h"

/**
 * clean_input -> removes trailing newline, checks if input is empty
 * @input: user's input
 *
 * Return: Nothing
 */

void clean_input(char *input)
{
	input[strcspn(input, "\n")] = '\0';

	if (strlen(input) == 0)
	{
		printf("You didn't enter any command. \n");
	}
}
