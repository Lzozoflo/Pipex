/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:23:46 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 10:33:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Applies a function to each character of a string using its index.
 * 
 * The `ft_strmapi` function iterates over the string `s` and applies the 
 * function `f` to each character of the string. The function `f` takes the 
 * index of the character and the character itself as parameters. The function 
 * returns a new string containing the results of applying `f` to each character 
 * of `s`. The resulting string is dynamically allocated and null-terminated.
 * 
 * @param s The string to modify.
 * @param f The function to apply to each character of the string, taking 
 *          the index and the character as arguments.
 * @return char* A new string containing the modified characters, or `NULL` 
 *               if memory allocation fails.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s)+1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
