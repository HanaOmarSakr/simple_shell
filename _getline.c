#include "main.h"

int _getline(char *line)
{
    size_t buffer = 0;
    int l;

    l = getline(&line, &buffer, stdin);
    return l;
}
