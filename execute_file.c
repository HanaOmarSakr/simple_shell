#include "main.h"


void execute_file(char *file_path) {
    pid_t pid = fork();
    char *argv[2];
    argv[0] = file_path;
    argv[1] = NULL;

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        if (execve(file_path, argv, NULL) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0); 
    }
}
