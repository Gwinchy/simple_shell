#include "shell.h"
void commands(char *command, char *args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(command, args, NULL);
	}
	if (execve == -1)
	{
		perror(execve);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror(fork);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0)
	}
}
