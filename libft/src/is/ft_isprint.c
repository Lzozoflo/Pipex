/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:11:35 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:31:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is printable.
 * 
 * The function `ft_isprint` tests whether the integer value `c` corresponds
 * to a printable character, meaning a character whose ASCII code is between
 * 32 (space) and 126 (tilde ~), inclusive.
 * 
 * @param c The character to test, represented as an integer (`int`).
 *          In C, characters are often passed as integers, allowing us to
 *          check their ASCII codes.
 * @return int Returns 1 if `c` is a printable character (between 32 and 126),
 *             and 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
