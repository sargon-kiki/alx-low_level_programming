#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
*close_file_desc - Closes file descriptors.
*@fd: The file descriptor to be closed.
*/
void close_file_desc(int fd)
{
int closed;

closed = close(fd);

if (closed == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* allocate_buffer - Allocates 1024 bytes for a buffer.
* @destination_file: The name of the file buffer is storing chars for.
* Return: A pointer to the newly-allocated buffer.
*/
char *allocate_buffer(char *destination_file)
{
char *new_buffer;

new_buffer = malloc(sizeof(char) * 1024);

if (new_buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", destination_file);
exit(99);
}

return (new_buffer);
}

/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success.
* Description: If the argument count is incorrect - exit code 97.

**/

int main(int argc, char *argv[])
{
int from_fd, to_fd, r, w;
char *buffer;
if (argc != 3)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

buffer = allocate_buffer(argv[2]);
from_fd = open(argv[1], O_RDONLY);
r = read(from_fd, buffer, 1024);
to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
	if (from_fd == -1 || r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	w = write(to_fd, buffer, r);
	if (to_fd == -1 || w == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	r = read(from_fd, buffer, 1024);
	to_fd = open(argv[2], O_WRONLY | O_APPEND);

} while (r > 0);

free(buffer);
close_file_desc(from_fd);
close_file_desc(to_fd);
return (0);
}
