#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{

    int fd;
    char *line;

    fd = open("get_next_line.c", O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        printf("%s\n", line);
        line = get_next_line(fd);
    }
}