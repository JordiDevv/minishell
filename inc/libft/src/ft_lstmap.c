/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:07:27 by rodrigo           #+#    #+#             */
/*   Updated: 2024/09/09 19:32:45 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_clearlst(t_list	*lst, void (*del) (void *))
{
	t_list	*aux;

	while (lst)
	{
		aux = lst;
		lst = aux->next;
		del(aux->content);
		free (aux);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*fnode;
	t_list	*nwnd;
	t_list	*aux;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	fnode = NULL;
	aux = lst;
	while (aux)
	{
		content = f(aux->content);
		nwnd = ft_lstnew(content);
		if (!nwnd)
		{
			del(content);
			ft_clearlst(fnode, del);
			return (NULL);
		}
		ft_lstadd_back(&fnode, nwnd);
		aux = aux->next;
	}
	return (fnode);
}

/* int	main(void)
{
	t_list	**lst;
	t_list	*aux;

	lst = malloc(sizeof(t_list *));
	if (!lst)
		return (1);
	*lst = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(lst, (void *) ft_strdup("second"));
	ft_lstadd_back(lst, (void *) ft_strdup("third"));
	ft_lstadd_back(lst, (void *) ft_strdup("fourth"));
	aux = *lst;
	while (aux)
	{
		printf("%s\n", (char *) aux->content);
		aux = aux->next;
	}
} */