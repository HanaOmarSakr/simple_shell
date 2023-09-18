#include "main.h"

/**
 * execute - ....
 * @line: string
 * Return: int
*/


void execute(char **argv)
{
    int check = execve(argv[0], argv, NULL);
    
    if (check == -1)
    {
            perror("Error");
    };
}
