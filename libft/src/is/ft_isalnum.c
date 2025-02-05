/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:34 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:34:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is alphanumeric.
 * 
 * The function `ft_isalnum` determines if the character passed as argument `c`
 * is alphanumeric, meaning it is either a letter (uppercase or lowercase) 
 * or a digit. It relies on the functions `ft_isalpha` and `ft_isdigit` to 
 * perform this check.
 * 
 * @param c The character to test, represented as an integer (`int`).
 *          In C, characters are often passed as integers, allowing us to 
 *          check their ASCII code.
 * @return int Returns 1 if the character is alphanumeric (letter or 
 *             digit), and 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
