#include "main.h"

char *nonint (char *line)
{
    char *temp;
    int check = 0;
    char **splitted;
    char *command;

    if (!_strchr(line, '|'))
        return (line);

    splitted = split_line(line, " \n");

    if (_strcmp(splitted[0], "echo") == 0)
    {
        _strtok(line, "\"");
        command = _strtok(NULL, "\"");
        check = 1;
    }
    
    if (check == 1)
    {
        return (command);
    }
    else {
        temp = strtok(line, "|");
        return (temp);
    }

}
