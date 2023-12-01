#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#define MAX_INPUT_SIZE 1014
#define MAX_ARGS 256
#define MAX_PATH_LENGTH 1024
extern char **environ;
void prompt(void);
void token(char input[], char *args[]);
void commands(char *cmd, char *args[]);
void handle_command(char *cmd, char *args[]);
#endif
