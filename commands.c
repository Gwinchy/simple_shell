#include "shell.h"
/**
 * commands - processes commands
 * @cmd: pointer to command
 * @args: pointer to arguments
 * Return: void
 */
void commands(char *cmd, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(cmd, args, environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal(SIGINT, sigint_handler);
		waitpid(pid, &status, 0);
	}
}
