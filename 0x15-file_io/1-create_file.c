#include "main.h"

/**
 * create_file - Creates a file.
 * standard output.
 * @filename: Name of the file to create.
 * @text_content: NULL terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, lenght;
	ssize_t ch_write;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content)
	{
		lenght = 0;
		while (*(text_content + lenght) != '\0')
			lenght++;
		ch_write = write(fd, text_content, lenght);
		if (ch_write == -1)
		{
			write(STDOUT_FILENO, "fails", 6);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
