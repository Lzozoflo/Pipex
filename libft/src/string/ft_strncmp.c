/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:25:20 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 11:42:51 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to a certain number of characters.
 * 
 * The `ft_strncmp` function compares the two strings `str1` and `str2` 
 * up to `len` characters. If a difference is found before reaching `len`, 
 * it returns the difference between the corresponding characters. If the 
 * two strings are equal up to `len` characters or until the end of one of 
 * them, it returns 0. The comparison is done on the characters as 
 * `unsigned char`.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param len The maximum number of characters to compare.
 * @return int The difference between the first unequal characters, or 0 
 *             if the strings are equal up to `len` characters.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
