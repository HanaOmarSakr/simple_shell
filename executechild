#include "main.h"

/**
 * execute_command - function that executes acommand child process.
 * @args: an array of pointer that stores
 *        the parsed the tokens from the user input.
 * @envp: an array of environment variables that is passed to execve function.
 * Return: value.
*/
void execute_command(char *args[], char *envp[])
{
	execve(args[0], args, envp);
	perror("execve");
	exit(1);
}
