/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:11:23 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/01 15:34:50 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*string_read_from_fd(int fd, char *first_str)
{
	int		b_read;
	char	*buffer;

	buffer = malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd > OPEN_MAX)
		return (free(buffer), buffer = NULL, NULL);
	b_read = 1;
	while (b_read != 0 && !ft_strchr(first_str, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			free(first_str);
			first_str = NULL;
			return (NULL);
		}
		buffer[b_read] = '\0';
		first_str = ft_strjoin(first_str, buffer);
	}
	free(buffer);
	return (first_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*first_str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	first_str[fd] = string_read_from_fd(fd, first_str[fd]);
	if (!first_str[fd])
		return (NULL);
	line = buff_to_line(first_str[fd]);
	first_str[fd] = next_line_from_buffer(first_str[fd]);
	return (line);
}
