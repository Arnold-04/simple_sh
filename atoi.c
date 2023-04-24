#include "shell.h"

/**
 * interactive - checks if the shell is in interactive mode
 * @info: struct containing information about the shell
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is an alphabetic character
 * @c: the character to check
 *
 * Return: 1 if the character is an alphabetic character, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the converted number if the string contains a number, 0 otherwise
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, flag = 0, output = 0;
	unsigned int result = 0;

	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
