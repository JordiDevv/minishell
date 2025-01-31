/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:15:32 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/24 19:30:11 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ex_nextcmd(t_data *program_data, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		close(program_data->pipe[i - 1][1]);
		close(program_data->fds[1]);
		dup2(program_data->pipe[i - 1][0], STDIN_FILENO);
		dup2(program_data->pipe[i][1], STDOUT_FILENO);
		if (execve(program_data->full_rute, program_data->split_cmd,
				program_data->environ) == -1)
			free_exit(program_data);
	}
	else
	{
		close(program_data->pipe[i - 1][1]);
		close(program_data->pipe[i - 1][0]);
		close(program_data->pipe[i][1]);
	}
}

void	ex_finalcmd(t_data *program_data, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		close(program_data->pipe[i - 1][1]);
		dup2(program_data->pipe[i - 1][0], STDIN_FILENO);
		dup2(program_data->fds[1], STDOUT_FILENO);
		if (execve(program_data->full_rute, program_data->split_cmd,
				program_data->environ) == -1)
			free_exit(program_data);
	}
	else
	{
		close(program_data->pipe[i - 1][1]);
		close(program_data->pipe[i - 1][0]);
	}
}

void	ex_cmd1(t_data *program_data, int argc)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		aux_ex_cmd1(program_data, argc);
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
