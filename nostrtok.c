#include "main.h"


char **my_strtok(char *str)
{
	char **tokens;
	char *token;
	int w;
	int m;
	int len;
	int count;

	len = 0;

	while (str[len] != '\0')
		len++;
	tokens = malloc(sizeof(char *) * (len + 1));
	if (tokens == NULL)
	{
		return (NULL);
	}
	w = 0;
	m = 0;
	count = 0;
	while (w < len)
	{
		while (str[w] && is_delim(str[w]))
			w++;
		token = malloc(sizeof(char) * (len + 1));
		if (token == NULL)
			return (NULL);
		while (str[w] && !is_delim(str[w]))
		{
			token[m] = str[w];
			w++;
			m++;
		}
		token[m] = '\0';
		tokens[count] = token;
		count++;
		m = 0;
	}
	tokens[count] = NULL;
	return (tokens);
}


int is_delim(char b)
{
	int w;

	w = 0;

	while (DELIM[w])
	{
		if (b == DELIM[w])
		{
			return (1);
		}
		w++;
	}
	return (0);
}
