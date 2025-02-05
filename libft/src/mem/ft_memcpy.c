/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:45:26 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/25 15:30:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a block of memory from a source to a destination.
 * 
 * The `ft_memcpy` function copies `size` bytes of memory from the block 
 * pointed to by `src` to the block pointed to by `dest`. If either `dest` 
 * or `src` pointers are invalid (NULL), the function returns `NULL`. 
 * The function does not handle cases where the memory blocks overlap; 
 * for this, `ft_memmove` should be used.
 * 
 * @param dest Pointer to the destination memory block.
 * @param src Pointer to the source memory block to copy from.
 * @param size The number of bytes to copy.
 * @return void* Pointer to the destination memory block (`dest`).
 */
void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
