#ifndef GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>


char    *get_next_line(int fd);
void    ft_bzero(void *str, size_t len);

void    *ft_calloc(size_t nitems, size_t size);
char    *ft_strchr(const char *s, int c);

size_t	ft_strlen(char *s);
char	*buff_to_line(char *buff);
char	*ft_strjoin(char *left_str, char *buff);
char	*next_line_from_buffer(char *buff);

#endif
#endif