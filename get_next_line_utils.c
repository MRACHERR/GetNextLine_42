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

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str + len_s1, s2, len_s2 + 1);
	return (str);
}