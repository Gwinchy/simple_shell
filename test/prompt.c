#include "shell.h"
#define MAX_INPUT_SIZE 1024
/**
 * display_prompt - displays user input
 * Return: user input
 */
void display_prompt(void)
{
	printf("$ ");
}
/**
 * main - starting point
 * Return: printed input
 */
int main(void)
{
	int status;
	char input[MAX_INPUT_SIZE];
	pid_t pid;

	while (1)
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\nExiting!\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		arguments();
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execlp(input, input, NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
