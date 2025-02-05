/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:13:21 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:33:48 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is alphabetic.
 * 
 * The function `ft_isalpha` tests if the character passed as argument `c` 
 * is an alphabetic letter, whether it is an uppercase ('A' to 'Z') or 
 * a lowercase ('a' to 'z'). It returns 1 if the character is alphabetic 
 * and 0 otherwise.
 * 
 * @param c The character to test, represented as an integer (`int`).
 *          In C, characters are often passed as integers, allowing us to 
 *          check their ASCII code.
 * @return int Returns 1 if the character is an alphabetic letter,
 *             0 otherwise.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
