#include "shell.h"
/**
 * token - tokenizes input
 * @input: text to  be tokenized
 * @args: arguments
 * Return: tokenized input
 */
void token(char input[], char *args[])
{
	char *token;
	int arg_count = 0;

	token = strtok(input, " \n");
	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \n");
	}
	args[arg_count] = NULL;
}
