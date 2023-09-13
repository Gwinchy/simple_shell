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
			perror("null");
			exit(EXIT_FAILURE);
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting my simple Shell...\n\n\n");
			exit(EXIT_SUCCESS);
		}
		get_path(input);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			process_arguments(input);
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
