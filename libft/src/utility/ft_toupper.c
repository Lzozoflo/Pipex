/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:46:53 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:08:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase character to uppercase.
 * 
 * The `ft_toupper` function takes a character as input and, if the character 
 * is a lowercase letter (between `'a'` and `'z'`), it converts it to uppercase
 * by subtracting 32 from its ASCII value. If the character is not a lowercase 
 * letter, it is returned unchanged.
 * 
 * @param c The character to convert.
 * @return int The converted uppercase character, or the unchanged character 
 *             if it is not a lowercase letter.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
