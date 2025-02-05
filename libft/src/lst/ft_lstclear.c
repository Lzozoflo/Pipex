/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:14:38 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/12 16:39:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes all elements of the list and frees their memory.
 *
 * The `ft_lstclear` function traverses the linked list pointed to by `lst`
 * and deletes each element by calling the `del` function on its content,
 * then frees the memory associated with each element. The list is then
 * cleared (the `*lst` pointer is set to NULL).
 *
 * @param lst A pointer to the pointer of the list head.
 * @param del The function to delete each element's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*templst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		templst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = templst;
	}
	*lst = NULL;
}

void	ft_delete_content(int content)
{
	(void)content;
}
