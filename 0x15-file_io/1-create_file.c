#include "main.h"
/**
 * create_file - creates a new file
 * @filename:  filename pointer
 * @text_content: string to write
 * Return: If the function fails - -1.
 *         Otherwise - 1.
*/

int create_file(const char *filename, char *text_content)
{
ssize_t main_fd = 0;
ssize_t writer = 0;
int len_text = 0;

if (filename == NULL)
{
return  (-1);
}

main_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
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
