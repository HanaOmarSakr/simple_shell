#include "main.h"

/**
 * getInput - ....
 * @path_file: file descriptor
 * Return: ..........
*/

char *getInput(char *path_file)
{
	static char buffer[BUFF_SIZE];
	static char *ptr = buffer;
	static int read_count;
	char *line;
	int len, fd = 0;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	line = malloc(BUFF_SIZE);
	if (!line)
		return (NULL);
	while (1)
	{
		read_count = read(fd, buffer, BUFF_SIZE);
		ptr = buffer;
		if (read_count <= 0)
			return (NULL);
		while (*ptr != '\n')
		{
			line[len++] = *ptr++;
			read_count--;
		}
		if (*ptr == '\n')
		{
			line[len] = '\0';
			ptr++;
			read_count--;
			return (line);
		}
		line = _realloc(line, BUFF_SIZE, (len + BUFF_SIZE));
		if (!line)
			return (NULL);
	}
}
