/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:14:02 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/18 17:52:08 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Removes characters from the beginning and end of a string.
 * 
 * The `ft_strtrim` function removes all characters present in the string
 * `set` from the beginning and end of the string `s1`. It scans `s1` from
 * both ends to identify and ignore the characters to be removed. A new 
 * string is dynamically allocated to contain the portion of `s1` that does 
 * not contain those characters. This new string is returned.
 * 
 * @param s1 The string to process.
 * @param set The string containing the characters to remove from the 
 *            beginning and end of `s1`.
 * @return char* A new string without the characters from `set` at the 
 *               beginning and end, or `NULL` if memory allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	str = malloc(j - i + 1);
	if (!str)
		return (NULL);
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
