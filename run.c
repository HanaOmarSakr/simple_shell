#include "main.h"

char **run (char *line)
{
    char *newline;
    char **splitted;

    newline = nonint(line);
    splitted = split_line(newline, " \n");
   /* if (_strcmp(splitted[0],"exit") == 0)
    {
        eexit = 1;
        return (NULL);
    } */
    if (can_execute(splitted[0]) == 1)
    {
        _printf("from run");
        return (splitted);
    }
        perror("Error");
        return (NULL);
}
