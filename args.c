#include "shell.h"
/**
 * process_arguments - handles arguments
 * @input: arguments input
 * Return: void
 */
void process_arguments(char *input)
{
	char *args[MAX_ARG_SIZE];
	char *token;
	pid_t pid;
	int arg_count = 0;

	token = strtok(input, " \t\n");
	while (token != NULL && arg_count < MAX_ARG_SIZE - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}
	if (arg_count == 0)
	{
		fprintf(stderr, "No command provided!\n");
		return;
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
		execve(args[0], args, NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
