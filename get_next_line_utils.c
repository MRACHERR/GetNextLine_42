#include "get_next_line.h"
void    *ft_calloc(size_t nitems, size_t size)
{
        void    *items;
        size_t  t;

        t = nitems * size;
        if (size != 0 && nitems != t / size)
                return (NULL);
        items = malloc(t);
        if (items == 0)
                return (NULL);
        ft_bzero(items, (nitems * size));
        return (items);
}

void    ft_bzero(void *str, size_t len)
{
        size_t                  i;
        unsigned char   *ptr;

        i = 0;
        ptr = (unsigned char *)str;
        while (i < len)
        {
                ptr[i] = 0;
                i++;
        }
}