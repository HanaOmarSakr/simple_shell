#include "main.h"

int main(int ac, char **argv){
    char *lineptr = NULL;
	char *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i = 0;


    (void)ac;

    while (true)
	{
        printf("%s", "$ ");
        nchars_read = getline(&lineptr, &n, stdin);
        /* check if the getline function failed or reached EOF or user use CTRL + D */ 
        if (nchars_read == -1){
            return (-1);
        }

        lineptr_copy = malloc(sizeof(char) * nchars_read);

        if (lineptr_copy == NULL)
		{
            perror("tsh: memory allocation error");
            return (-1);
        }
        
        _strcpy(lineptr_copy, lineptr);

        /********** split the string (lineptr) into an array of words ********/

        /* calculate the total number of tokens */
        token = strtok(lineptr, delim);

        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim); /*CONTINUE WHERE U STOPPED*/
        }
        num_tokens++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * num_tokens);

        /* Store each token in the argv array */
        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
		{
            argv[i] = malloc(sizeof(char) * _strlen(token));
            _strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;


        printf("%s\n", lineptr);

        free(lineptr);
    } 


    return (0);
}
