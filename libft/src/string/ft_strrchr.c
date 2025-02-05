/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:46:05 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/19 14:17:55 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the last occurrence of a character in a string.
 * 
 * The `ft_strrchr` function searches for the last occurrence of the 
 * character `s` in the string `str`. It starts searching from the end 
 * of the string and moves backward to the beginning. If the character 
 * `s` is found, the function returns a pointer to the last occurrence 
 * of `s` in `str`. If `s` is not found, the function returns `NULL`.
 * 
 * @param str The string in which to search.
 * @param s The character to search for in the string.
 * @return char* A pointer to the last occurrence of `s` in `str`, or 
 *               `NULL` if `s` is not found.
 */
char	*ft_strrchr(const char *str, int s)
{
	size_t	i;

	i = ft_strlen(str);
	while (str && str[i] != (char)s && i > 0)
		i--;
	if (str[i] == (char)s)
		return ((char *)&str[i]);
	return (NULL);
}
