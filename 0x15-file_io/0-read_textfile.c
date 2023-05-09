#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t write_fd, read_fd, main_fd;
buf = malloc(sizeof(char) * letters);

	main_fd = open(filename, O_RDONLY);
	if (main_fd == -1)
		return (0);
	read_fd = read(main_fd, buf, letters);
	write_fd = write(STDOUT_FILENO, buf, read_fd);
	close(main_fd);
free(buf);
	return (write_fd);
}
