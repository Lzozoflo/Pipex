/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:23:21 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 16:32:19 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element to the end of the list.
 * 
 * The `ft_lstadd_back` function adds the `new` element to the end of 
 * the linked list pointed to by `lst`. If the list is empty (`*lst` is 
 * NULL), `new` becomes the first element. Otherwise, the function 
 * traverses the list to the last element and attaches `new` to it.
 * 
 * @param lst A pointer to the pointer of the list's head.
 * @param new The element to add to the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*templs;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		templs = ft_lstlast(*lst);
		templs->next = new;
	}
}
