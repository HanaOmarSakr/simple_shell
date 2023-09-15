#include "main.h"

/**
 * main - entry point.
 * @line: char array that store the user input.
 * @args: an array of pointer that store the parsed tokens from user input.
 * @envp: environment variable for execve().
 * Return: (0).
*/
int main()
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
	}
	else if (pid == 0)
	{
		printf("Child process\n");
	}
	else
	{
		printf("Parent process\n");
	}
	while (true)
	{
		char *line;
		size_t len = 0;
		char *args[10];
		char *token;
		int i = 0;

		write(STDOUT_FILENO, "myshell> ", 9);
		getline(&line, &len, stdin);
		token = strtok(line, " \n");
		while (token != NULL && i < 9)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;
		if (args[0] == NULL)
		{
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			break;
		}
		pid = fork();
		if (pid == -1)
			perror("Error:");
		else if (pid == 0)
			execve(args[0], args, NULL);
		else
			wait(NULL);
	}
	return (0);
}
