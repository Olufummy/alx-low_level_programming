#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output.
 * @filename: file.
 * @letters: number of letters it should read and print.
 *
 * Return: actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, ch_read, ch_write;
	char *buf;

	if (filename == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == 0)
		return (free(buf), 0);
	ch_read = read(fd, buf, letters);
	if (ch_read == -1)
	{
		return (free(buf), 0);
	}
	ch_write = write(STDOUT_FILENO, buf, ch_read);
	if (ch_write == -1 || ch_read != ch_write)
	{
		return (free(buf), 0);
	}
	free(buf);
	close(fd);
	return (ch_write);
}
