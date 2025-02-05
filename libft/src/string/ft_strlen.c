/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:14:52 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:15:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the length of a string.
 * 
 * The `ft_strlen` function iterates over the string `str` and returns 
 * the number of characters before the null character (`\0`). It does not 
 * count the null terminator. The function stops as soon as it encounters 
 * this null character.
 * 
 * @param str The string whose length is to be determined.
 * @return size_t The length of the string, i.e., the number of characters 
 *                before the null character.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
