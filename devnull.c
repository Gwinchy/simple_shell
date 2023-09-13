#include "shell.h"
/**
 * devnull - blocks child process
 * Return: void
 */
void devnull(void)
{
	int devnull;

	devnull = open("/dev/null", O_WRONLY);
	if (devnull == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(devnull, STDOUT_FILENO);
	close(devnull);
}
