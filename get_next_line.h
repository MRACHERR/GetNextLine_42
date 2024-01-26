#ifndef GET_NEXT_LINE
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#define GET_NEXT_LINE 
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
void    ft_bzero(void *str, size_t len);

void    *ft_calloc(size_t nitems, size_t size);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
#endif