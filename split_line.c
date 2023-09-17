#include "main.h"

char **split_line(char *str, const char delim)
{
    char *lineptr_copy;
    char *token;
    char **argv;
    int num = 0;
    int i;

    lineptr_copy = malloc(sizeof(char) * strlen(str));
    if (lineptr_copy == NULL)
    {
        perror("Memory allocation error: ");
        return NULL;
    }

    strcpy(lineptr_copy, str);
    /* calculate the total number of tokens */
    token = strtok(str, &delim);
    while (token != NULL)
    {
        num++;
        token = strtok(NULL, &delim); /*CONTINUE WHERE U STOPPED*/
    }

    argv = malloc(sizeof(char *) * (num + 1));
    /* Store each token in the argv array */
    token = strtok(lineptr_copy, &delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = malloc(sizeof(char) * strlen(token));
        strcpy(argv[i], token);
        token = strtok(NULL, &delim);
    }
    argv[i] = NULL;

    return argv;
}
