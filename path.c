#include "shell.h"
/**
 * handle_command - handles PATH
 * @cmd: command
 * @args: arguments
 * Return: Void
 */
void handle_command(char *cmd, char *args[])
{
	char *path_env;
	char *path_copy, *path_token, command_path[MAX_PATH_LENGTH];

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "PATH environment not found\n");
		return;
	}
	path_copy = strdup(path_env);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", path_token, cmd);
		if (access(command_path, X_OK) == 0)
		{
			commands(command_path, args);
			free(path_copy);
			return;
		}
		path_token = strtok(NULL, ":");
	}
	fprintf(stderr, "%s: command not found\n", cmd);
	free(path_copy);
}
