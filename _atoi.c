#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: structure address
 *
 * Return: 1 if interactive, ELSE 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks to see if char is delimeter
 * @c: character to check
 * @delim: delimeter string
 * Return: 1 if true, else 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabet char
 * @c: The character to input
 * Return: 1 if c is an alphabet, else 0 if otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to integer
 * @s: the string to convert
 * Return: 0 if no number in string, else gives converted number
 */

int _atoi(char *s)
{
	int I; 
int si = 1; 
int fl = 0; 
int output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			si *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			fl = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (si == -1)
		output = -result;
	else
		output = result;

	return (output);
}
