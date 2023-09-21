#include <stdlib.h>

/**
 * freeptp - ..........
 * @pp: .......
 * Return: nothing
 */

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

/**
 * my_exit - ..........
 * Return: nothing
 */
void my_exit(void)
{
    exit(0);
}
