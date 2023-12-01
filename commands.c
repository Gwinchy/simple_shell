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
	int status, access_result;

	access_result = access(cmd, X_OK);
	if (access_result == -1)
	{
		fprintf(stderr, "%s: No such file or directory\n", cmd);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, args, NULL) == -1)
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
		waitpid(pid, &status, 0);
	}
}
