/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/24 19:23:35 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ex_cmd2(t_data *program_data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		dup2(program_data->pipe[0][0], STDIN_FILENO);
		dup2(program_data->fds[1], STDOUT_FILENO);
		if (execve(program_data->full_rute, program_data->split_cmd,
				program_data->environ) == -1)
			free_exit(program_data);
	}
	else
		close(program_data->pipe[0][0]);
}

void	ex_cmd1(t_data *program_data, int argc)
{
	pid_t	pid;

	argc++;
	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		close(program_data->pipe[0][0]);
		dup2(program_data->fds[0], STDIN_FILENO);
		dup2(program_data->pipe[0][1], STDOUT_FILENO);
		if (program_data->cmd1)
		{
			if (execve(program_data->full_rute, program_data->split_cmd,
					program_data->environ) == -1)
				free_exit(program_data);
		}
	}
	else
		close(program_data->pipe[0][1]);
}
