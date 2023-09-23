#include "main.h"

int can_execute(char *command)
{
    int result = system(command);
    if (result == -1) {
        return 0;
    } else {
        if (WIFEXITED(result) && WEXITSTATUS(result) == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}
