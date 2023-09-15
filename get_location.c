#include "shell.h"
/**
 * get_location - finds an exe file from the path
 * @command: command parsed
 * Return: path to a function
 */
char *get_location(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	int command_length = strlen(command);
	int directory_length = strlen(path_token);
	char *file_path = malloc(directory_length + command_length + 2);
	struct stat buffer;

	if (path)
	{
		while (path_token != NULL)
		{
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
