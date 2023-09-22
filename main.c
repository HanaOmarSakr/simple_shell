#include "main.h"

/**
 * main - .........
 * @argc: .........
 * @argv: .........
 * Return: ........
 */

int main(int argc, char **argv)
{
	char *error, *input = NULL;
	char **splitted;
	ssize_t check;
	
	if (argc == 2)
	{
		error = (getInput(argv[1]));
		if (_strcmp(error, "error")== 0)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_printf("%s: Can't open %s\n", argv[1], argv[0]);
				exit(127);
			}
		exit(EXIT_FAILURE);
		}
	}
	else
	{
		execute(split_line(getInput(argv[1]), " \n"));
	}

	while (true)
	{

		_printf("$ ");
		check = _getline(&input);
		splitted = split_line(input, " \n");
		if (_strcmp((splitted[0]), "exit") == 0)
			check = -1;
		else if (iscommand(get_path(splitted[0])) == 1)
			execute(splitted);
		if (check == -1)
			return (-1);
		free(input);
		freeptp(splitted);
	}
	return (0);
}
