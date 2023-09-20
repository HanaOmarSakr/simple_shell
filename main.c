#include "main.h"

int main(int argc, char **argv)
{
	char *input = NULL;
	char **splitted;
	ssize_t check;

	while (true)
	{
		if (argc == 2)
			execute_file(get_path(argv[1]));

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
