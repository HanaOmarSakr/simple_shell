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
	int check;

	(void)argc;
	(void)argv;

	if (argc == 2)
		execute(split_line(getInput(argv[1]), " \n"));
	while (true)
	{
		_printf("$ ");
		check = _getline(&input);
		splitted = run(input);
		if (check == -1)
			return (-1);
		free(input);
		freeptp(splitted);
	}
	return (0);
}
