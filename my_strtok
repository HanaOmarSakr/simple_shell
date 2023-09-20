#include "main.h"
/*
char **my_strtok(char *str)
{
    int i = 0, j = 0;
    char **tokens = malloc((strlen(str) + 1) * sizeof(char *));
    char *token = malloc(strlen(str) + 1);

    while (*str)
    {
        while (*str && is_delim(*str))
            str++;
        while (*str && !is_delim(*str))
            token[j++] = *str++;
        token[j] = '\0';
        if (j > 0)
        {
            tokens[i] = malloc(j + 1);
            if (tokens[i])
            {
                strcpy(tokens[i], token);
                i++;
            }
            j = 0;
        }
    }
    tokens[i] = NULL;
    free(token);

    return (tokens);
}

/**
 * is_delim - checks if character is a delimeter.
 * @g: the char to check.
 * @delim: the dekimeter string.
 * Return: 1 is true, 0 is false.
 */
int is_delim(char g)
{
    char *delim = " \n";

	while (delim)
    {
        if (*delim++ == g)
		return (1);
	}
	return (0);
}
