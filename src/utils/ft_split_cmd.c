/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:34:46 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/28 12:34:17 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_fractol.h"
#include "libft.h"

// ft_is_white_space(*s)

static int	ft_num_word(const char *s, int *double_quote)
{
	int	iw;
	int	i;

	i = 0;
	iw = 0;
	*double_quote = 0;
	while (*s)
	{
		if (*s == '"' && *double_quote == 1)
			*double_quote = 0;
		else if (*s == '"')
			*double_quote = 1;
		else if (*double_quote == 0 && iw == 0 && !ft_is_white_space(*s))
		{
			iw = 1;
			i++;
		}
		else if (*double_quote == 0 && iw == 1 && ft_is_white_space(*s))
			iw = 0;
		s++;
	}
	return (i);
}

static int	ft_len_word(const char *str)
{
	int	i;

	i = 0;
	while (*str && !ft_is_white_space(*str))
	{
		str++;
		i++;
	}
	return (i);
}

static int	ft_len_space(const char *str)
{
	int	double_quote;
	int	i;

	i = 0;
	double_quote = 0;
	while (*str)
	{
		if (*str == '"')
			double_quote = !double_quote;
		if (!double_quote && !ft_is_white_space(*str) && *str != '"' )
			break ;
		str++;
		i++;
	}
	return (i);
}

// int	main()
// {
// 	int i = 8;
// 	char *str = "oui oui \"oui\" non bb";
// 	while (i--)
// 	{
// 		printf("%d\n str = %s \n", ft_len_space(str, ' '), str);
// 		str = str + ft_len_word(str, ' ') + ft_len_space(str, ' ');

// 	}
// }

char	**ft_split_cmd(char const *s)
{
	char	**str;
	int		double_quote;
	int		i;
	int		nw;

	i = 0;
	nw = ft_num_word(s, &double_quote);
	if (double_quote == 1)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (nw + 1));
	if (!str)
		return (NULL);
	while (nw--)
	{
		s = s + ft_len_space(s);
		str[i] = ft_substr(s, 0, ft_len_word(s));
		if (!str[i])
			return (ft_freetab(str, i));
		s = s + ft_len_word(s);
		i++;
	}
	str[i] = NULL;
	return (str);
}
