#include <stdlib.h>

void freeptp(char **pp)
{
    char **a = pp;
    char *p;

    if (!pp)
        return;
    while ((p = *pp++))
        free(p);
    free(a);
}
