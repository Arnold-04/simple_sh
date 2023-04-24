#include "shell.h"
#include <unistd.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

/**
 * _eputs - prints a string to stderr
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(const char *str)
{
	if (!str)
		return;
	int i = 0;

	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes a character to stderr
 * @c: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	int i = 0;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		if (write(STDERR_FILENO, buf, i) < 0)
			return (-1);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes a character to a file descriptor
 * @c: the character to print
 * @fd: the file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	int i = 0;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		if (write(fd, buf, i) < 0)
			return (-1);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints a string to a file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters printed
 */
int _putsfd(const char *str, int fd)
{
	if (!str)
		return (0);
	int i = 0;

	while (str[i] != '\0')
	{
		if (_putfd(str[i], fd) < 0)
			return (-1);
		i++;
	}
	return (i);
}
