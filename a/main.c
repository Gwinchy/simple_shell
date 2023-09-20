#include "shell.h"
/**
 * prompt - displays a prompt
 * Return: prompt input
 */
void prompt(void)
{
	printf("Simple_shell -$ ");
	fflush(stdout);
}
/**
 * main - starting point
 * Return: Always 0 success
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	ssize_t nread;

	prompt();
	while (1)
	{
		nread = read_input(input, sizeof(input));
		if (nread == 0)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		input[nread - 1] = '\0';
		execute_command(input);
	}
	return (0);
}
