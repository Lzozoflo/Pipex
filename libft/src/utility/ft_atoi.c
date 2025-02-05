/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:49:15 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/27 14:45:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * The function `ft_atoi` takes a string as input and converts the numeric
 * part of the string into an integer of type `int`. It ignores leading
 * whitespace, handles the signs (+/-), and stops when a non-numeric character
 * is encountered.
 *
 * @param str The string to convert to an integer.
 *
 * @return int The resulting integer from the conversion of the string.
 *             Returns 0 if no digits are present.
 */
int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

long int	ft_atol(const char *str)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

double	ft_atod(const char *str)
{
	double	res;
	double	sign;
	double	fraction;
	int		i;

	res = 0.0;
	sign = 1.0;
	fraction = 1.0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1.0;
	while ((str[i] >= '0' && str[i] <= '9'))
		res = res * 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while ((str[i] >= '0' && str[i] <= '9' ))
		{
			fraction *= 0.1;
			res += (str[i++] - '0') * fraction;
		}
	}
	return (res * sign);
}

// int	main(void)
// {
// // 	// int i = ft_atoi("-1225322222222222");
// // 	// long int l = ft_atol("-1225322222222222");

// // 	// printf("%d\n%ld", i , l);
// // 	// if (i != ft_atol("-1225322222222"))
// // 	// {
// // 	// 	return (1);
// // 	// }
// 	int	icap = 3;
// 	int	fcap = 9;
// 	double feur;
// 	double j = atof("-123.1234567891");
// 	double i = ft_atod("-123.1234567891", &icap, &fcap);
// 	feur = 775286848841080.1451429;
// 	printf("%.10f \n", feur);
// 	printf("%.10f , %d, %d\n", i, icap,fcap);
// 	printf("%.10f , %d, %d", j, icap,fcap);
// 	return 0;
// }
