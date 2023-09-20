#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
ssize_t read_input(char *buffer, size_t size);
void execute_command(char *command);
#endif
