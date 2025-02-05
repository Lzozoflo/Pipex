/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:55:11 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/03 09:08:30 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_size_base(int nbr, int base)
{
	int	i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char	ft_convert_base(unsigned long nbr, int base, const char format)
{
	char	*s;

	if (base > 36 || base <= 1)
		return (0);
	if (format == 'X')
		s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		s = "0123456789abcdefghijklmnopqrstuvwxyz";
	return (s[nbr % base]);
}
