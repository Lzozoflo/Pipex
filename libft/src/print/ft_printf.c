/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:00:01 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/10 16:07:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_format(const char format, va_list args)
{
	int		count;
	int		isneg;
	void	*ptr;

	count = 0;
	isneg = 0;
	ptr = va_arg(args, void *);
	if (ptr == 0 && format == 'p')
		isneg = ft_putstr("(nil)");
	else if (ptr != 0 && format == 'p')
	{
		isneg = ft_putstr("0x");
		if (isneg < 0)
			return (-1);
		count += isneg;
		isneg = ft_putnbr_base_unsign((unsigned long)ptr, 16, format);
	}
	if (isneg < 0)
		return (-1);
	return (count + isneg);
}

/**
 * @brief Handles displaying data based on a format character.
 *
 * This function displays formatted data according to the `format` character.
 * It retrieves arguments from `args` using `va_arg` and calls the appropriate
 * function to perform the display.
 *
 * @param format A character specifying the format type:
 *               - '%' : Displays a percentage symbol '%'.
 *               - 'c' : Displays a character.
 *               - 's' : Displays a string.
 *               - 'd' or 'i' : Displays a signed integer (base 10).
 *               - 'u' : Displays an unsigned integer (base 10).
 *               - 'x' : Displays an unsigned integer (hex, lowercase).
 *               - 'X' : Displays an unsigned integer (hex, uppercase).
 *               - 'p' : Prefixed with "0x", displays a pointer in hex, .
 *
 * @param args A `va_list` containing the values to display as per the format.
 *
 * @return int The number of characters displayed. Returns `-1` if the format
 *             is unrecognized.
 *
 * @note Functions like `ft_putchar`, `ft_putstr`, etc., must be defined to
 *       handle the display and formatting for numeric bases.
 */
static int	ft_what_format(const char format, va_list args)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), 10, format));
	else if (format == 'u')
		return (ft_putnbr_base_unsign(va_arg(args, unsigned int), 10, format));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_base_unsign(va_arg(args, unsigned int), 16, format));
	else if (format == 'p')
		return (ft_ptr_format(format, args));
	return (-1);
}

static int	ft_format_or_char(const char **format, va_list args)
{
	int	isneg;

	if (**format == '%')
	{
		(*format)++;
		isneg = ft_what_format(**format, args);
	}
	else
		isneg = ft_putchar(**format);
	if (isneg < 0)
		return (-1);
	return (isneg);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		isneg;

	count = 0;
	if (!format)
		return (-1);
	if (format)
	{
		va_start(args, format);
		while (*format != '\0')
		{
			isneg = ft_format_or_char(&format, args);
			if (isneg < 0)
				return (-1);
			count += isneg;
			format++;
		}
		va_end(args);
	}
	return (count);
}
