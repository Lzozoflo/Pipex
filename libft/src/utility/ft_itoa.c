/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 08:57:27 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/21 07:44:28 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the number of digits in an integer.
 * 
 * The `get_num_len` function determines the length (in terms of digits) 
 * of the integer `n`. If `n` is negative, the function accounts for 
 * the sign and adjusts the length accordingly. The value `-2147483648` 
 * is a special case, requiring 11 digits.
 * 
 * @param n The integer whose number of digits is to be calculated.
 * @return int The number of digits required to represent `n`.
 */
static int	get_num_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

/**
 * @brief Converts an integer to a string.
 * 
 * The function `ft_itoa` converts an integer `n` to a string representation.
 * It handles the special case of the smallest integer `-2147483648` due to
 * the limitations of integer ranges, and returns it directly as a string.
 * For other values, it allocates memory for the resulting string and fills
 * it with the digits of the integer, considering the sign if the number is
 * negative.
 * 
 * @param n The integer to be converted to a string.
 * @return char* A string representing the integer `n`, or `NULL` if memory
 *               allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = get_num_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
