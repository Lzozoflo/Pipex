/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:36:11 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 13:02:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for a substring in a string up to a given length.
 * 
 * The `ft_strnstr` function searches for the first occurrence of the 
 * string `cmp` in the string `str`, but it is limited to `len` characters 
 * of `str`. If `cmp` is an empty string, the function immediately returns 
 * `str`. The search is performed on the first `len` characters of `str`, 
 * and if the substring `cmp` is found, a pointer to its first character 
 * in `str` is returned. If `cmp` is not found within this limit, the 
 * function returns `NULL`.
 * 
 * @param str The string in which to search.
 * @param cmp The string to search for in `str`.
 * @param len The maximum number of characters from `str` to consider 
 *            for the search.
 * @return char* A pointer to the start of the first occurrence of `cmp` 
 *               in `str`, or `NULL` if `cmp` is not found.
 */
char	*ft_strnstr(const char *str, const char *cmp, size_t len)
{
	size_t	i;
	size_t	j;

	if (*cmp == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && cmp[j] && str[i + j] == cmp[j] && (i + j) < len)
			j++;
		if (!cmp[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
