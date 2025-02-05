/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:00:39 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/28 12:04:14 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_is_white_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
