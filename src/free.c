/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:33:37 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/20 12:59:52 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"
#include "../inc/executor.h"

/*frees environment*/
int	ft_free_env(char **env)
{
	int	i;

	if (!env)
		return (-1);
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free (env);
	return (0);
}

/*frees nodes of commands*/
void	ft_free_nodes(t_list *lst)
{
	t_list	*aux;
	t_list	*aux2;

	if (!lst)
		return ;
	aux = lst;
	while (aux)
	{
		aux2 = aux->next;
		free (((t_cmd *) aux->content)->split);
		free (aux->content);
		free (aux);
		aux = aux2;
	}
}
