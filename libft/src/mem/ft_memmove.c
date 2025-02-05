/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:56 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/25 15:30:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a block of memory from source to destination, even if 
 *        the blocks overlap.
 * 
 * The `ft_memmove` function copies `size` bytes of memory from the block 
 * pointed to by `src` to the block pointed to by `dest`. It correctly handles 
 * cases where the memory blocks overlap. If the blocks overlap in such a way 
 * that the destination is before the source, the function copies the bytes 
 * from the end of the source block to the end of the destination block. If 
 * either `dest` or `src` pointers are invalid (NULL), the function returns 
 * `NULL`.
 * 
 * @param dest Pointer to the destination memory block.
 * @param src Pointer to the source memory block to copy from.
 * @param size The number of bytes to copy.
 * @return void* Pointer to the destination memory block (`dest`).
 */
void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && d < s + size)
	{
		while (size-- > 0)
			d[size] = s[size];
	}
	else
	{
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
