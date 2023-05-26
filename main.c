#include "shell.h"

/**
 * freeData -> Function that frees data structure
 *
 * @datash: data structure
 * Return: Nothing
 */

void freeData(dataShell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * setData -> Function that initialize data structure
 * @datash: data structure
 * @argv: argument vector
 * Return: Nothing
 */

void setData(dataShell *datash, char **argv)
{
	unsigned int i;

	datash->argv = argv;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	data->pid = aux_itoa(getpid());
}

/**
 * main -> Entry point
 *
 * @argc: Argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	dataShell datash;
	(void) argc;

	signal(SIGINT, get_sigint);
	setData(&datash, argv);
	shell_loop(&datash);
	freeData($datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
