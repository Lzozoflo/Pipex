/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:55:57 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 12:58:56 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string.
 * 
 * The `ft_strdup` function allocates memory for a new string and copies 
 * the content of the string `src` into it. It returns a pointer to the 
 * new string. If the allocation fails, it returns `NULL`.
 * 
 * @param src The string to duplicate.
 * @return char* A pointer to the new duplicated string, or `NULL` if memory 
 *               allocation fails.
 */
char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	i;

	i = ft_strlen(src);
	cpy = (char *)malloc((i + 1));
	if (!cpy)
		return (NULL);
	cpy[i] = '\0';
	while (i-- > 0)
		cpy[i] = src[i];
	return (cpy);
}
