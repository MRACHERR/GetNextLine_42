#include <stdio.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    int b_read;
    char    *buffer;
    if (fd < 0)
        return (NULL);

    buffer = calloc((3 + 1) , sizeof(char));
    if (!buffer)
        return (NULL);
    b_read = read(fd, buffer, 3);
    if (b_read <= 0)
        return (NULL);
    return (buffer);
}