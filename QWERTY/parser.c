#include "shell.h"
/**
 * parse_line - splits commands
 * @line: user input
 * Return: tokens
 */
char **parse_line(char *line)
{
int buffer_size = 64;
char **tokens = malloc(buffer_size * sizeof(char *));
char *token;
int position = 0;

if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= buffer_size)
{
buffer_size += 64;
tokens = realloc(tokens, sizeof(char *)*buffer_size);
if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return (tokens);
}

