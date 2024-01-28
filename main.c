#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>


void f()
{
    system("leaks a.out");
}
int main()
{
    atexit(f);// 0x7fe576c05850
    int fd;
    char *line;
    // int count;
    // char *buffer;
    // int b_read;

    fd = open("get_next_line.h", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    close(fd);
    // buffer = malloc(5 + 1 * sizeof(char));
    // b_read = 1;
    // while (b_read != 0 && !ft_strchr(buffer, '\0'))
    // {
    //     b_read = read(fd , buffer, 5);
    //     printf("line[]: %s\n", buffer);
    // }
    // while (line)
    // {
    // line = get_next_line(fd);
    // printf("line[]: %s\n", line);
    // free(line);
    // // buffer = get_next_line(fd);
    // // printf("line[]: %s\n", buffer);
    // // free(buffer);
    // // close(fd);
    // }
}