#include <stdio.h>
#include "get_next_line.h"

char *ft_read_str(fd, first_string)
{
    int     b_read;
    char    *buffer;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    b_read = 1;
    while (b_read != 0 , !ft_strchr(first_string,'\n'))
    {
        b_read = read(fd, buffer,BUFFER_SIZE);
        if (b_read == -1)
        {
            free(b_read);
            return (NULL);
        }
        buffer[b_read]= '\0';
        first_string = ft_strjoin(first_string, buffer);
    }
    free(buffer);
    return (first_string);

}

char *get_next_line(int fd)
{
    char    *line;
    char    *first_str;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    first_str = calloc((BUFFER_SIZE + 1) , sizeof(char));
    if (!first_str)
        return (NULL);
    line = ft_read_str(fd, first_str);
    //first_str += line;
    
    return (line);
}