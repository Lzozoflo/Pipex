/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:49:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/22 17:52:42 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

static char	*ft_mmv(char *buff, char *line)
{
	char	*newline;
	int		i;

	i = 0;
	newline = ft_strchr(buff, '\n');
	while (newline[i])
		i++;
	if (newline)
		ft_memmove(buff, newline + 1, i + 1);
	return (line);
}

static char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s2[i] && s2[i] != '\n')
		i++;
	if (s2[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(s1) + i + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i - 1] != '\n')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

static char	*ft_check_strjoin(char *s1, const char *s2)
{
	char	*str;

	str = NULL;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = ft_strjoin_gnl(s1, s2);
	if (!str)
		return (NULL);
	return (str);
}

// ft_bzero(buff, BUFFER_SIZE);
static char	*ft_reader(int fd, char *buff, char *line)
{
	int		r_read;

	while (1)
	{
		if (buff[0] == '\0')
		{
			r_read = read(fd, buff, BUFFER_SIZE);
			if (r_read < 0)
			{
				if (line)
					free(line);
				return (NULL);
			}
			if (r_read == 0)
				return (line);
			buff[r_read] = '\0';
		}
		line = ft_check_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			return (ft_mmv(buff, line));
		buff[0] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_reader(fd, buff, line);
	if (!line)
		return (NULL);
	return (line);
}
