/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:15:49 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/27 12:03:10 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates one string to another with a maximum size limit.
 *
 * The `ft_strlcat` function concatenates the string `src` to the string
 * `dest` while respecting a maximum size `size`. It appends the characters
 * from `src` to the end of `dest`, without exceeding the given maximum size.
 * If the size of `dest` is greater than or equal to `size`, the concatenation
 * will not be performed, but the total length of the resulting string is
 * returned.
 *
 * @param dest The destination string to append the characters from `src`.
 * @param src The source string to concatenate to `dest`.
 * @param size The maximum size of the resulting string (including the `\0`).
 * @return size_t The total length of the resulting string, i.e., the length
 *                of `dest` NUM_PAD_PLUS the length of `src`,
 * without exceeding `size`.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;

	d = (ft_strlen(dest));
	if (size <= d || size == 0)
		return (size + ft_strlen(src));
	while (d < (size - 1) && *src)
		dest[d++] = *src++;
	dest[d] = '\0';
	return (d + ft_strlen(src));
}
