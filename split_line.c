#include "main.h"
/**
 * split_line - ....
 * @str: string
 * @delim: space
 * Return: splitted line (pointer to a pointer)
*/

char **split_line(char *str, char *delim)
{
	char *lineptr_copy;
	char *token;
	char **argv;
	int num = 0;
	int i;

	lineptr_copy = malloc(sizeof(char) * (_strlen(str) + 1));
	if (lineptr_copy == NULL)
	{
		perror("Memory allocation error: ");
		return (NULL);
	}

	_strcpy(lineptr_copy, str);
	/* calculate the total number of tokens */
	token = _strtok(str, delim);
	while (token != NULL)
	{
		num++;
		token = _strtok(NULL, delim); /*CONTINUE WHERE U STOPPED*/
	}

	argv = malloc(sizeof(char *) * (num + 1));
	/* Store each token in the argv array */
	token = _strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(argv[i], token);
		token = _strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(lineptr_copy);
	return (argv);
}
