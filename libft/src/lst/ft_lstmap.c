/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:15 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 09:54:09 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each element of a list and returns a new list.
 *
 * This function iterates over the linked list `lst`, applying the function `f`
 * to the content of each element. It creates a new list where each element is
 * the result of applying `f` to the corresponding element in the original list.
 * If an error occurs (e.g., memory allocation failure or `f` returns `NULL`),
 * the new list is cleared using the `del` function.
 *
 * @param lst The head of the list to iterate over.
 * @param f The function to apply to each element. It takes a pointer to the
 *          content of the element and returns a pointer to the modified content.
 * @param del The function to free the content of an element in case of an error.
 *
 * @return t_list* A pointer to the new list. Returns `NULL` if an error occurs.
 *
 * @note The new list's memory is allocated using `malloc`. Make sure to free
 *       the list after use.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*new_content;

	head = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
