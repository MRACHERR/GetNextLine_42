#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	len_s1;
// 	size_t	len_s2;

// 	if (s1 == NULL && s2 == NULL)
// 		return (NULL);
// 	if (s1 == NULL)
// 		return (ft_strdup(s2));
// 	if (s2 == NULL)
// 		return (ft_strdup(s1));
// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, len_s1 + 1);
// 	ft_strlcat(str + len_s1, s2, len_s2 + 1);
// 	return (str);
// }

char	*buff_to_line(char *buff)
{
	char	*line;
	int i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)malloc((2 + i) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while( buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line_from_buffer(char *buff)
{
	int i;
	int j;
	char *str;
	i = 0;

	while(buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(buff) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = '\0';
	free(buff);
	return (str);
}
