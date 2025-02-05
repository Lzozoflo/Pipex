/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:36:57 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:20:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the first occurrence of a value in a memory block.
 * 
 * The `ft_memchr` function scans the first `n` bytes of the memory block
 * pointed to by `p` and returns a pointer to the first occurrence of the
 * value `v` (converted to `unsigned char`). If the value is not found,
 * the function returns `NULL`.
 * 
 * @param p Pointer to the memory block to examine.
 * @param v The value to search for, converted to `unsigned char`.
 * @param n The number of bytes to examine in the memory block.
 * @return void* A pointer to the first occurrence of `v`, or `NULL` if
 *                the value is not found.
 */
void	*ft_memchr(const void *p, int v, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)p;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)v)
			return ((unsigned char *)&str[i]);
		i++;
	}
	return (NULL);
}
