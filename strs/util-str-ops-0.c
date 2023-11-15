#include "monty.h"

/**
 * _getline - read a line into s, return length
 * @s: buffer to read into
 * @lim: maximum line length
 * @f: file stream to readlines from
 *
 * Return: The number of characters read or 0 if non
 */
size_t _getline(char s[], int lim, FILE *f)
{
	int c; /* The character read */
	int i; /* counter variable */

	for (i = 0; (c = fgetc(f)) != EOF && c != '\n'; i++)
	{
		if (i >= lim - 1)
			s = resize_mem(s, &lim);
		s[i] = c;
	}

	if (c == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (c == EOF ? EOF : i);
}

/**
 * resize_mem - resizes the memory to twice the size of lim
 * @s: the buffer to resize
 * @lim: current maximum buffer size
 *
 * Return: the newly resized buffer with all contents of the old copied over
 */
char *resize_mem(char *s, int *lim)
{
	char *mem;
	unsigned int i;

	*lim *= 2;
	mem = malloc(sizeof(char) * *lim);

	if (mem == NULL)
		return (NULL);

	i = 0;
	while ((mem[i] = s[i++]) != '\0')
		; /* This copies the '\0 as well */

	free(s);
	return (mem);
}

/**
 * _dprintf - prints formatted text into a file descriptor
 * @fd: file descriptor
 * @format: the format string
 *
 * Return: number of bytes written
 */
size_t _dprintf(const int fd, const char *format, ...)
{
	/**
	 * OTHER C89 compliant alternatives
	 * printf - print a simple formatted string to stdout
	 * fprintf - print a simple formatted string to stdout
	 * sprintf - create a simple formatted string
	 * vprintf - print to stdout with formatter and va_list
	 * vfprintf - write to stream with formatter and va_list
	 * vsprintf - create a string with formatter and va_list
	 **/
	int written, buffer_size;
	va_list args;
	char buffer[MAX_LINE];

	va_start(args, format);

	buffer_size = vsprintf(buffer, format, args);
	written = write(fd, buffer, buffer_size);
	va_end(args);
	return (written);
}
