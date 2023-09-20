#include "shell.h"
/**
 * execute_command - Executes a command
 * @command: arguments to be passed
 * Return: void
 */
void execute_command(char *command)
{
	char *argv[2] = {NULL, NULL};
	pid_t pid;
	int status;

	argv[0] = strtok(command, " ");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
