/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:43:56 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:32:31 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is in the ASCII table.
 * 
 * The function `ft_isascii` tests if the integer value `c` corresponds to a
 * valid ASCII character. The standard ASCII table defines 128 characters,
 * with codes ranging from 0 to 127 inclusive. If `c` is within this range,
 * it is considered an ASCII character.
 * 
 * @param c The character to test, represented as an integer (`int`).
 *          In C, characters are often passed as integers, allowing us to
 *          check their ASCII codes.
 * @return int Returns 1 if `c` is a valid ASCII character (0 to 127),
 *             and 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}
