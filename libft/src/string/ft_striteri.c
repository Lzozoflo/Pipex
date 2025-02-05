/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:33:30 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/18 18:05:07 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string, with its index.
 * 
 * The `ft_striteri` function iterates over the string `str` and applies 
 * the function `f` to each character of the string, passing the index of 
 * each character and a pointer to it. This allows modifying each character 
 * of the string according to the logic defined by the function `f`.
 * 
 * @param str The string to process.
 * @param f The function to apply to each character, taking the index and 
 *          a pointer to the character.
 */
void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
