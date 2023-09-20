#include "main.h"

/**
 * execute - ....
 * @argv: pointer to a pointer
 * Return: int
*/


void execute(char **argv)
{
	pid_t pid = fork();
	int check;

	if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
		if (argv)
		{
			check = execve(get_path(argv[0]), argv, NULL);
			if (check == -1)
				perror("Error");
		}
	}
    else 
	{
        int status;
        waitpid(pid, &status, 0); 
    }
}
