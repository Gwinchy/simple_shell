#include "shell.h"
#define MAX_INPUT_SIZE 1024
/**
 * display_prompt - displays user input
 */
void display_prompt(void)
{
	printf("simple_shell...$ ");
	fflush(stdout);
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
		process_arguments(input);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			devnull();
			execlp(input, input, NULL);
			perror("exec");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
