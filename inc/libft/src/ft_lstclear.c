/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:33:03 by rodrigo           #+#    #+#             */
/*   Updated: 2024/09/09 19:32:22 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*aux;
	t_list	*aux2;

	if (!lst || !*lst)
		return ;
	aux = *lst;
	while (aux)
	{
		aux2 = aux->next;
		del(aux->content);
		free (aux);
		aux = aux2;
	}
	*lst = NULL;
}

/*int	main(void)
{
	t_list	**lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*aux;

	lst = malloc(sizeof(t_list));
	node1 = ft_lstnew("first");
	node2 = ft_lstnew("last");
	ft_lstadd_front(lst, node1);
	ft_lstadd_back(lst, node2);
	aux = node1;
	printf("size before = %d\n", ft_lstsize(node1));
	while (aux)
	{
		printf("%s\n", (char *) aux->content);
		aux = aux->next;
	}
	ft_lstclear(lst, ft_lstdelone);
	printf("after %s\n", (char *) node2->content);
} */
