#include "main.h"

/**
_strcpy - copies a string to a buffer
@dest: destination buffer
@src: source buffer
Return: pointer "start" which is the beginning of "dest"
Description: important func
*/
char *_strcpy(char *dest, const char *src)
{
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
_strlen - gets lenght of string
@buffer: string
Return: length of "buffer"
Description: important func
*/
int _strlen(char *buffer)
{
    int i = 0;

    while (*buffer++ != '\0')
        i++;

    return (i);
}
