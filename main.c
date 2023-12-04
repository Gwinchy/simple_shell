#include "shell.h"
/**
 * main - starting point
 * @argc: argument counter
 * @argv: argument vector
 * Return: Always 0 Success
 */
int main(int argc, char **argv)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];

	while (1)
	{
		prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		if (strncmp(input, "exit", 4) == 0)
		{
			exit(EXIT_SUCCESS);
		}
		token(input, args);
		handle_command(args[0], args);
	}
	return (0);
}
