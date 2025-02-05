/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:27:04 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/20 09:23:17 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list element.
 *
 * The `ft_lstnew` function creates a new list element, allocates memory
 * for a `t_list` element, and initializes its `content` field with the
 * `content` value passed as an argument. The `next` field is initialized
 * to `NULL`, indicating that this element has no next element.
 *
 * @param content The content to associate with the new list element.
 * @return t_list* The new list element, or `NULL` if memory allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*chain;

	chain = (t_list *)malloc(sizeof(t_list));
	if (!chain)
		return (NULL);
	if (!content)
		chain->content = NULL;
	else
		chain->content = content;
	chain->next = NULL;
	return (chain);
}
