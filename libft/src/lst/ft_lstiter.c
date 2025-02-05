/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:54:12 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/18 10:54:44 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each element of the list.
 * 
 * The `ft_lstiter` function traverses the linked list pointed to by `lst`
 * and applies the function `f` to each element of the list. The function `f`
 * is applied to the content of each list element.
 * 
 * @param lst The list on which to apply the function.
 * @param f The function to apply to each element of the list.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
