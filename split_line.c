#include "main.h"
/**
 * split_line - ....
 * @str: string
 * @delim: space
 * Return: splitted line (pointer to a pointer)
*/

char **split_line(char *str)
{
	char *lineptr_copy;
	char *token;
	char **argv;
	int num = 0;
	int i;

	lineptr_copy = malloc(sizeof(char) * (strlen(str) + 1));
	if (lineptr_copy == NULL)
	{
		perror("Memory allocation error: ");
		return (NULL);
	}

	strcpy(lineptr_copy, str);
	/* calculate the total number of tokens */
	token = strtok(str);
	while (token != NULL)
	{
		num++;
		tokenmy_strtok(NULL); /*CONTINUE WHERE U STOPPED*/
	}

	argv = malloc(sizeof(char *) * (num + 1));
	/* Store each token in the argv array */
	tokenmy_strtok(lineptr_copy);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);
		tokenmy_strtok(NULL);
	}
	argv[i] = NULL;

	free(lineptr_copy);
	return (argv);
}
