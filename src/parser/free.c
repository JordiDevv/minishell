/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:33:37 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/04 03:03:19 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/executor.h"

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
		if (((t_cmd *) aux->content)->built)
			free (((t_cmd *) aux->content)->built);
		free (aux->content);
		free (aux);
		aux = aux2;
	}
}

void	ft_free_ex(t_data *data)
{
	int	i;

	i = 0;
	if (data->pipe_fds)
	{
		while (data->pipe_fds[i])
			free(data->pipe_fds[i++]);
		free(data->pipe_fds);
	}
	return ;
}

void	ft_free_all(t_data *data, t_msh *msh)
{
	ft_free_ex(data);
	if (data->doors)
		free(data->doors);
	ft_free_env(msh->env);
	if (msh->input && !data->should_exit)
		free(msh->input);
	if (data->exported_vars)
		ft_free_matrix(data->exported_vars);
	return ;
}
