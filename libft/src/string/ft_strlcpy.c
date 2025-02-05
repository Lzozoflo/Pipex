/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:38:09 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 13:01:25 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a source string into a destination string with a size limit.
 * 
 * The `ft_strlcpy` function copies up to `size - 1` characters from the 
 * string `src` into the string `dst`. It ensures that the string `dst` is 
 * always null-terminated (`\0`). If the size of `dst` is insufficient, 
 * the copy stops and a null character is placed at the end. It returns 
 * the total length of `src`, i.e., the length the string `dst` would have 
 * obtained if `dst` had been large enough.
 * 
 * @param dst The destination string to copy `src` into.
 * @param src The source string to copy into `dst`.
 * @param size The maximum size of the destination string, including the 
 *             null character.
 * @return size_t The total length of `src`, i.e., the number of characters 
 *                in `src` excluding the null character.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while ((i < (size - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
