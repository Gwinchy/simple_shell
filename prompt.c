#include "shell.h"
/**
 * prompt - prints prompt to screen
 * Return: void
 */

void prompt(void)
{
	char text[] = "Simple_shell_$	";
	int i;

	for (i = 0; text[i] != '\0'; i++)
	{
		_putchar(text[i]);
	}
}
