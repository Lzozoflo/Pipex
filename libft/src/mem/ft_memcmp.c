/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:06:00 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 11:50:02 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares the first `size` bytes of two memory blocks.
 * 
 * The `ft_memcmp` function compares the bytes of the memory blocks pointed
 * to by `p1` and `p2` for the first `size` bytes. It returns a negative
 * integer if the first differing byte in `p1` is less than in `p2`, a positive
 * integer if the opposite is true, and 0 if the memory blocks are equal.
 * 
 * @param p1 Pointer to the first memory block to compare.
 * @param p2 Pointer to the second memory block to compare.
 * @param size The number of bytes to compare.
 * @return int A negative, positive integer, or 0 based on the byte comparison.
 */
int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = p1;
	str2 = p2;
	i = 0;
	while (i < size)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
