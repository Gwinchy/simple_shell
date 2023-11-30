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
ssize_t _putchar(char c);
void prompt(void);

#endif
