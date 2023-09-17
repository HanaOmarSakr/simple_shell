#include "main.h"

int main()
{
	char *lineptr = NULL;
	char **splitted;
	ssize_t nchars_read;
	int i = 0;

	while (true)
	{
		_printf("%s", "$ ");
		nchars_read = _getline(&lineptr);
		/* check if the getline function reached EOF or user use CTRL + D */
		if (nchars_read == -1)
			return (-1);

		splitted = split_line(lineptr, ' ');
		i = 0;
		while (splitted[i])
		{
				_printf("%s\n", splitted[i]);
				i++;
		}
		free(splitted);
		free(lineptr);
	}
	return (0);
}
