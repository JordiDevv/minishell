/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:46:04 by rodrigo           #+#    #+#             */
/*   Updated: 2024/09/09 19:32:28 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free (lst);
	lst = NULL;
	return ;
}

/* void	ft_del(void *content)
{
	return ;
}

int	main(void)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (1);
	lst->content = "hello";
	lst->next = NULL;
	ft_lstdelone(lst, ft_del);
	printf("deleted node = %s\n", (char *) lst->content);
} */