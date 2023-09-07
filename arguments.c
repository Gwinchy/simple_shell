#include "shell.h"
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
/**
 * display_prompt - displays user input
 * Return: user input
 */
void display_prompt(void)
{
	printf("simple_shell...$ ");
}
/**
 * main - starting point
 * Return: printed input
 */
int main(void)
{
	int status;
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARG_SIZE];
	pid_t pid;
	char *token;
	int arg_count = 0;

	while (1)
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\nExiting!\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		token = strtok(input, " ");
		while (token != NULL)
		{
			args[arg_count] = token;
			arg_count++;
			if (arg_count >= MAX_ARG_SIZE -1)
			{
				printf(stderr, "Too many arguments!'\n");
				break;
			}
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execvp(args[0], args);
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
