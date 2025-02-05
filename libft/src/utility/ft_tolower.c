/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:28:28 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:09:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to lowercase.
 * 
 * The `ft_tolower` function takes a character as input and, if the character is
 * an uppercase letter (between `'A'` and `'Z'`), it converts it to a lowercase
 * letter by adding 32 to its ASCII value. If the character is not an uppercase 
 * letter, it is returned unchanged.
 * 
 * @param c The character to convert.
 * @return int The converted lowercase character, or the unchanged character
 *             if it's not an uppercase letter.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
