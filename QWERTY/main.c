#include "shell.h"
/**
 * main - starting point
 *
 * Return: Output
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args;

while (1)
{
printf("($) "); /* Display the prompt*/
read = getline(&line, &len, stdin);

if (read == -1)
{
printf("\n"); /*Handle Ctrl+D (end of file)*/
free(line);
exit(EXIT_SUCCESS);
}

/* Remove the newline character at the end of the command*/
if (line[read - 1] == '\n')
{
line[read - 1] = '\0';
}

args = parse_line(line);
free(line);
free(args);
}
return (EXIT_SUCCESS);
}
