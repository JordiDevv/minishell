/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:45:17 by rodrigo           #+#    #+#             */
/*   Updated: 2024/09/09 19:32:56 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/* int	main(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	if (!node1 || !node2)
		return (1);
	node1->content = "node1";
	node1->next = node2;
	node2->content = "node2";
	node2->next = NULL;
	printf("elementos = %d\n", ft_lstsize(node1));
} */