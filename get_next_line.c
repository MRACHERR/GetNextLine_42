#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


char    *string_read_from_fd(int fd, char *first_str)
{
    int b_read;
    char    *buffer;
    
    buffer = malloc((1 + BUFFER_SIZE) * sizeof(char));
    if (!buffer)
        return (NULL);
    b_read = 1;
    while (b_read != 0 && !ft_strchr(first_str, '\n'))
    {
        b_read = read(fd , buffer, BUFFER_SIZE);
        if (b_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[b_read] = '\0';
        first_str = ft_strjoin(first_str, buffer);
    }
    free(buffer);
    return (first_str); 
}



char    *get_next_line(int fd)
{
    char    *line;
    static char    *first_str;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    first_str = string_read_from_fd(fd, first_str);
    if (!first_str)
        return (NULL);
    line = buff_to_line(first_str);
    first_str = next_line_from_buffer(first_str);
    return (line);
}