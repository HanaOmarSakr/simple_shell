#include "main.h"

/**
 * main - .........
 * @argc: .........
 * @argv: .........
 * Return: ........
 */

int main(int argc, char **argv)
{
	char *input = NULL;
	char **splitted;
	ssize_t check;

	if (argc == 2)
		execute(split_line(getInput(argv[1]), " \n"));

	while (true)
	{

		_printf("$ ");
		check = _getline(&input);
		/* check if the getline function reached EOF or user use CTRL + D */
		if (check == -1)
			return (-1);

		splitted = split_line(input, " \n");
		execute(splitted);
	}
	free(input);
	freeptp(splitted);
	return (0);
}
