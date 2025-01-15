/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:41:43 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/05/14 17:07:30 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*a_lst;

	if (!lst || !f)
		return ;
	a_lst = lst;
	while (a_lst)
	{
		f(a_lst->content);
		a_lst = a_lst->next;
	}
}
