#include "shell.h"
/**
 * execmd - esecutes commands
 * @argv: argument array
 * Return: output
 */
void execmd(char **argv)
{
	char *command = NULL;
	char *actual_command = get_location(command);

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("execve");
		}
	}
}
