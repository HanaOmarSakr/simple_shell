#include "main.h"

/**
 * execute - ....
 * @argv: pointer to a pointer
 * Return: int
*/


void execute(char **argv)
{
	int check = execve(argv[0], argv, NULL);

	if (check == -1)
	{
		perror("Error");
	};
}
