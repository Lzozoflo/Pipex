/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:53:12 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/25 19:02:04 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string followed by a newline to a file.
 * 
 * The `ft_putendl_fd` function writes the string `s` to the file or stream 
 * specified by the file descriptor `fd`, then adds a newline character (`\n`) 
 * at the end.
 * 
 * @param s The string to write.
 * @param fd The file descriptor or output stream to write the string to.
 */
ssize_t	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = ft_putstr_fd(s, fd);
	i += ft_putchar_fd('\n', fd);
	return (i);
}

ssize_t	ft_putendl(char *s)
{
	int	i;

	i = ft_putstr(s);
	i += ft_putchar('\n');
	return (i);
}
