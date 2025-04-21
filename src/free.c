/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:33:37 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/21 11:32:14 by rhernand         ###   ########.fr       */
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

void	ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
		
		ft_free_matrix(((t_cmd *) aux->content)->split);
		free (aux->content);
		free (aux);
		aux = aux2;
	}
}

void	ft_free_all(t_data *data, t_msh *msh)
{
	int	i;

	i = 0;
	if (data->doors)
		free(data->doors);
	if (data->split_path)
	{
		while (data->split_path[i])
			free (data->split_path[i++]);
	}
	free (data->split_path);
	if (data->full_rute)
		free(data->full_rute);
	if (msh->input)
		free (msh->input);
	if (msh->prompt)
		free (msh->prompt);
	ft_free_env(msh->env);
	ft_free_nodes(msh->lst);
	return ;
}
