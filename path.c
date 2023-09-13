#include "shell.h"
/**
 * get_path - finds path to execute a command
 * @input: user text input
 * Return: void
 */
void get_path(char *input)
{
	char *path = "/bin:/usr/bin";
	char *token;
	char full_path[MAX_INPUT_SIZE];
	pid_t pid;
	int status;
	char *args[2];

	args[0] = full_path;
	args[1] = NULL;
	token = strtok(path, ":");
	while (token != NULL)
	{
		printf(full_path, sizeof(full_path), "%s%s", token, input);
		if (access(full_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				devnull();
				execve(full_path, args, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(&status);
			}
		}
		token = strtok(NULL, ":");
	}
}
