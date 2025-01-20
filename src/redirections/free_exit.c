/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:39:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/15 12:15:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	close_pipes(t_data *program_data)
{
	int	i;

	i = 0;
	while (program_data->pipe[i])
	{
		if (program_data->pipe[i][0])
			close(program_data->pipe[i][0]);
		if (program_data->pipe[i][1])
			close(program_data->pipe[i][1]);
		i++;
	}
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	if (mat)
	{
		while (i > 0)
			free ((mat)[--i]);
		free (mat);
		mat = NULL;
	}
}

void	free_exit(t_data *program_data)
{
	if (program_data->fds[0] > 0)
		close(program_data->fds[0]);
	if (program_data->fds[1])
		close(program_data->fds[1]);
	if (program_data->pipe)
	{
		close_pipes(program_data);
		free_mat((char **)program_data->pipe);
		program_data->pipe = NULL;
	}
	if (program_data->path_mat)
		free_mat(program_data->path_mat);
	if (program_data->full_rute)
	{
		free(program_data->full_rute);
		program_data->full_rute = NULL;
	}
	if (program_data->split_cmd)
		free_mat(program_data->split_cmd);
	if (program_data->limiter)
	{
		free(program_data->limiter);
		program_data->limiter = NULL;
	}
	exit (EXIT_SUCCESS);
}
