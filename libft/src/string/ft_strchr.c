/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:34:14 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/18 15:25:34 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the first occurrence of a character in a string.
 * 
 * The `ft_strchr` function searches for the first occurrence of the character 
 * `c` in the string `str`. It returns a pointer to the position in the string. 
 * If the character is not found, it returns `NULL`.
 * 
 * @param str The string to search in.
 * @param c The character to search for (as an integer, treated as a `char`).
 * @return char* A pointer to the first occurrence of the character in the 
 *               string, or `NULL` if not found.
 */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
