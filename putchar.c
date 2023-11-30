#include "shell.h"
/**
 * _putchar - prints a character to the stdout
 * return: void
 */
ssize_t _putchar(char c)
{
	return write(STDOUT_FILENO, &c, 1);
}
