#include "shell.h"
/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * This function frees the memory that was allocated to the pointer
 * and sets its value to NULL.
 *
 * Return: 1 if freed, 0 otherwise.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
