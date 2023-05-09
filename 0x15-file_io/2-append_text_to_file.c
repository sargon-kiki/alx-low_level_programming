#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
ssize_t main_fd;
ssize_t writer;
int len_text = 0;

if (filename == NULL)
{
return  (-1);
}

main_fd = open(filename, O_APPEND | O_WRONLY);
if (main_fd == -1)
{
return (-1);
}
while (text_content[len_text] != '\0')
{
len_text++;
}

writer = write(main_fd, text_content, len_text);
if (writer == -1)
{
return (-1);
}
close(main_fd);
return (1);

}
