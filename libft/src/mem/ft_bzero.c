/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:44:37 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 17:01:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Initialise une zone mémoire avec des zéros.
 *
 * La fonction `ft_bzero` remplit les `c` premiers octets de la zone mémoire
 * pointée par `p` avec des zéros (valeur de byte 0). Cette fonction est
 * souvent utilisée pour initialiser ou réinitialiser des zones mémoire.
 *
 * @param p Pointeur vers la zone mémoire à initialiser.
 * @param c Nombre d'octets à mettre à zéro dans la zone mémoire.
 */
void	ft_bzero(void *p, size_t c)
{
	size_t			i;

	i = 0;
	while (i < c)
		((char *)p)[i++] = 0;
}
