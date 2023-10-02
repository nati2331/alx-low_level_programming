#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - it is a function that reads letters.
 * @filename - it is the text file being read.
 * @letters: it is the number of letters read
 * Return - w actual number of bytes printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

