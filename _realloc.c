#include "main.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;

    if (new_size == old_size)
        return ptr;

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;

    if (ptr != NULL)
    {
        _memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
        free(ptr);
    }

    return new_ptr;
}
