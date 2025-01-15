/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:42:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/05/14 17:08:27 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*current;
	void	*n_content;
	t_list	*n_node;

	if (!lst || !f || !del)
		return (NULL);
	n_lst = NULL;
	current = lst;
	while (current)
	{
		n_content = f(current->content);
		n_node = ft_lstnew(n_content);
		if (!n_node)
		{
			del(n_content);
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, n_node);
		current = current->next;
	}
	return (n_lst);
}
