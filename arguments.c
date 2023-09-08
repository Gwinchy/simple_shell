#include "shell.h"
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
/**
 * arguments - handles arguments
 * Return: execute argguments
 */
int arguments(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARG_SIZE];
	pid_t pid;
	char *token;
	int arg_count = 0;

	if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
	{
		perror("fgets");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, "\t\n");
	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		if (arg_count >= MAX_ARG_SIZE - 1)
		{
			fprintf(stderr, "Too many arguments!\n");
			break;
		}
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("exec");
		exit(EXIT_FAILURE);

	}
	return (0);
}
