#include "shell.h"
/**
 * read_input - Reads user input
 * @buffer: buffer to capture input
 * @size: input size
 * Return: number of characters read
 */
ssize_t read_input(char *buffer, size_t size)
{
	ssize_t nreads;

	nreads = read(STDIN_FILENO, buffer, size);
	if (nreads == -1)
	{
		perror("read");
		_exit(EXIT_FAILURE);
	}
	return (nreads);
}
