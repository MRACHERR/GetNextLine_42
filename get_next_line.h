/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:07:55 by acherraq          #+#    #+#             */
/*   Updated: 2024/01/28 17:41:06 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*buff_to_line(char *buff);
char	*ft_strjoin(char *left_str, char *buff);
char	*next_line_from_buffer(char *buff);

#endif