/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:34:15 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/11 13:30:04 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_atoi_alloc(char *str)
{
	int	*alloc;

	alloc = malloc(sizeof(int));
	if (!alloc)
		return (NULL);
	*alloc = ft_atoi(str);
	return (alloc);
}
