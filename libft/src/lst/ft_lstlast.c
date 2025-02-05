/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:12:37 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/13 11:21:42 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Retrieves the last element of the list.
 * 
 * The `ft_lstlast` function traverses the linked list pointed to by `lst`
 * and returns the last element of the list. If the list is empty, the
 * function returns `NULL`.
 * 
 * @param lst The list from which to retrieve the last element.
 * @return t_list* The last element of the list, or `NULL` if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
