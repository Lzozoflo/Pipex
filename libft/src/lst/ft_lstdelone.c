/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:35:42 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:22:08 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes a list element and frees its memory.
 * 
 * The `ft_lstdelone` function deletes an element from the linked list by
 * calling the `del` function on its content, then freeing the memory
 * allocated for that element.
 * 
 * @param lst The list element to delete.
 * @param del The function used to delete the element's content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
