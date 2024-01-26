#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>

int main()
{
    int fd;
    char *line;
    int count;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("line[]: %s\n", line);
}