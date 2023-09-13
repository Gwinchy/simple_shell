#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
void display_prompt(void);
void process_arguments(char *input);
void devnull(void);
void get_path(char *input);
#endif
