#include "shell.h"

/**
 * main - Starting point
 *
 * Return: 0 Always successful
 */

int main(void)
{
	char *command;
	char *argv[4];
	int status;
	pid_t pid;

	command = "/simple_shell/ex_path/my-exe";
	argv[] = {command, "arg1", "arg2", NULL};
	if (access(command, X_OK) == -1)
	{
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(command, argv);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Child process exited with status %d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}

