#include "main.h"

/**
 * wait_child - waits for child process to terminate and prints its status.
 * @status: integer that store the exit status of child process.
 * Return: value
*/
void wait_child(pid_t pid)
{
	int status;
	(void) pid;
	wait(&status);
	if (WIFEXITED(status))
	{
		printf("Child process exited with code %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		printf("Child process terminated by signal %d\n", WTERMSIG(status));
	}
}
