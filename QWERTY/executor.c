#include "shell.h"
/**
 * execute_command - executes command using execve
 * @args: arguments presented
 * Return: Output
 */
int execute_command(char **args)
{
pid_t pid;
int status;
char *path = "/bin/";
pid = fork();
if (pid == 0)
{

char *full_path = malloc(strlen(path) + strlen(args[0]) + 1);
if (full_path == NULL)
{
perror("Shell");
exit(EXIT_FAILURE);
}
strcpy(full_path, path);
strcat(full_path, args[0]);

if (execve(full_path, args, NULL) == -1)
{
perror("Shell");
}
free(full_path);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Shell");
}
else
{
do {
pid = waitpid(pid, &status, WUNTRACED);
}
while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}

