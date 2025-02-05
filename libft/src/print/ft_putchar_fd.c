/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:53:34 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/25 18:36:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character to a file or output stream.
 * 
 * The `ft_putchar_fd` function writes the character `c` to the file or 
 * stream specified by the file descriptor `fd`. It uses the `write` function 
 * to perform the write operation.
 * 
 * @param c The character to write.
 * @param fd The file descriptor or output stream to write the character to.
 */
ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
