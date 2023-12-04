#include "shell.h"
/**
 * sigint_handler - signal
 * @sig: signal
 * Return: signal
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
