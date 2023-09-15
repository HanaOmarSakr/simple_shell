#include "main.h"

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char *args[MAXARG];
    char *envp[] = {"path=/bin", NULL};
    pid_t pid;
    int status;
    while (1)
    {
        _printf("simple_shell$ ");
        if (fgets(line, MAXLINE, stdin) == NULL)
        {
            _printf("\n");
            exit(0);
            }
            line[strcspn(line, "\n")] = 0;
            if (strlen(line) == 0)
            {
                continue;
                }
                args[0] = strtok(line, " ");
                int i = 1;
                while (args[i-1] != NULL && i < MAXARG)
                {
                    args[i] = strtok(NULL, " ");
                    i++;
                    }
                    if (strcmp(args[0], "exit") == 0)
                    {
                        exit(0);
                        }
                        pid = fork();
                        if (pid == 0)
                        {
                            execve(args[0], args, envp);
                            perror("execve");
                            exit(1);
                            }
                            else if (pid > 0)
                            {
                                wait(&status);
                                if (WIFEXITED(status))
                                {
                                    _printf("Child process exited with code %d\n", WEXITSTATUS(status));
                                }
                                    else if (WIFSIGNALED(status))
                                    {
                                        _printf("Child process was killed by signal %d\n", WTERMSIG(status));
                                    }
                            }
                            else
                            {
                                perror("fork");
                                exit(2);
                        }
    }
                                return 0;
}

