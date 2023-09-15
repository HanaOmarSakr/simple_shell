#include "main.h"

/**
 * main - Entry point.
 * Description: Creates a child process using fork.
 * @pid: The process ID of the child process.
 * Return: Always 0 (Success)
 */
int main()
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		printf("Child process\n");
	}
	else
	{
		printf("Parent process\n");
	}
	return (0);
}
