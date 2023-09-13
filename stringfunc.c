#include "main.h"

/**
_strcpy - .....
@dest: ....
@src: ....
Return: pointer "start" which is the beginning of "dest"
*/
char *_strcpy(char *dest, const char *src) {
    char *start = dest;

    while(*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return (start);
}

/**
_strlen - .....
@buffer: ....
Return: length of "buffer"
*/
int _strlen(char *buffer)
{
    int i = 0;

    while (*buffer++ != '\0')
        i++;

    return (i);
}
