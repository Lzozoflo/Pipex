/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:21:35 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/14 17:17:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element to the beginning of the list.
 * 
 * The `ft_lstadd_front` function inserts the `new` element at the front 
 * of the linked list pointed to by `lst`. If the list is empty, `new` 
 * becomes the first element. Otherwise, it becomes the head of the list,
 * and its `next` field points to the previous first element.
 * 
 * @param lst A pointer to the pointer of the list's head.
 * @param new The element to add to the front of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
