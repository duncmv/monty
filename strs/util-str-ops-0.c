#include "main.h"
#define IN 1  /* Inside space characters */
#define OUT 0 /* Outside space characters */

/**
 * getline - read a line into s, return length
 * @line: buffer to read into
 * @lim: the limit of characters read
 *
 * Return: The number of characters read or 0 if non
 */
int _getline(char s[], int lim, FILE *f)
{
	int c; /* The character read */
	int i; /* counter variable */

	for (i = 0; i < lim - 1 && (c = fgetc(f)) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (i);
}

/**
 * copy - copy 'from' into 'to'; assum 'to' is big enough
 * @from: the source
 * @to: the destination
 *
 * Return: void
 * NOTE: Assume that 'to' is big enough
 */
void _copy(char to[], char from[])
{
	int i; /* counter variable */

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}

/**
 * reverse - reverses the string s
 * @s: the string to reverse
 *
 * Return: void
 */
void _reverse(char s[])
{
	char tmp; /* Temporary variable */
	int i, j; /* counter variables */

	/* Advance i to the end of the string just before the null */
	for (i = 0; s[i] && s[i + 1]; i++)
		;
	for (j = 0; j < i; j++, i--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

/**
 * atoi: converts s into integer
 * @s: a string of digits
 *
 * Return: integer result of the conversion
 */
int _atoi(char s[])
{
	char sign; /* The sign if present */
	int i;	   /* counter variable */
	int n;	   /* stores the total of computation */

	for (i = 0; isspace(s[i]); i++) /* skip the leading spaces */
		;
	sign = (s[0] == '-') ? -1 : 1; /* defaults to + */
	if (s[0] == '-' || s[0] == '+')
		i++; /* skip the sign */
	for (n = 0; isspace(s[i]); i++)
		n = n * 10 + (s[i] - '0');
	return (sign * n);
}

/**
 * lower - converts an uppercase character to lowercase
 * @c: the character to convert
 *
 * Return: the converted character
 */
char _lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	return (c);
}
