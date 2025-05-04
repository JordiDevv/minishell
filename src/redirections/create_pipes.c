/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:47:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/05 00:19:24 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static int	count_pipes(t_list *lst)
{
	int	n;

	n = 0;
	if (((t_cmd *)lst->content)->del)
		n++;
	while (lst->next)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

static int	*create_pipe(void)
{
	int	*pipe_fd;

	pipe_fd = malloc(sizeof(int) * 2);
	if (!pipe_fd)
	{
		write(2, "Error allocating a pipe\n", 24);
		return (NULL);
	}
	if (pipe(pipe_fd) < 0)
	{
		write(2, "Error creating a pipe\n", 22);
		return (NULL);
	}
	return (pipe_fd);
}

int	**prepare_pipes(t_list *lst)
{
	int	**pipe_fds;
	int	n_pipes;

	n_pipes = count_pipes(lst);
	if (n_pipes == 0)
		return (NULL);
	pipe_fds = malloc(sizeof(int *) * (n_pipes + 1));
	if (!pipe_fds)
	{
		write(2, "Error allocating the pipes array\n", 33);
		return (NULL);
	}
	pipe_fds[n_pipes] = NULL;
	while (--n_pipes > -1)
		pipe_fds[n_pipes] = create_pipe();
	return (pipe_fds);
}

pid_t	*prepare_pids(t_list *lst)
{
	int		n_pids;
	pid_t	*pids;

	n_pids = count_pipes(lst);
	if (!((t_cmd *)lst->content)->built)
		n_pids += 1;
	if (!n_pids)
		return (NULL);
	pids = malloc(sizeof(pid_t) * (n_pids + 1));
	if (!pids)
	{
		write(2, "Error allocating the pids array\n", 32);
		return (NULL);
	}
	while (--n_pids > -1)
		pids[n_pids] = 0;
	return (pids);
}
