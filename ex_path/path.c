#include "shell.h"
char *command;
pid_t pid;
int status;

int main()
{
	command = "/simple_shell/ex_path/";
	if (access(command, X_OK) == -1)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(fork);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(command, args);
		perror(execvp);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("%d\n", WEXITSTATUS(status));;
		}
	}
	return (0);
}

