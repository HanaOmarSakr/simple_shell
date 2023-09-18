#include "main.h"

int main()
{
	char *input = NULL;
	char **splitted;
	ssize_t check;

	while (true)
	{
		_printf("%s", "$ ");
		check = _getline(&input);
		/* check if the getline function reached EOF or user use CTRL + D */
		if (check == -1)
			return (-1);

		splitted = split_line(input, " \n");
		execute(splitted);
	}
	free(input);
	free(splitted);
	return (0);
}
