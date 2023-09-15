/* File 2: shell.h (Header File) */

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **parse_line(char *line);
int execute_command(char **args);

#endif /* SHELL_H */
