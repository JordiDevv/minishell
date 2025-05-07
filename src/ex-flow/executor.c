/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:11 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/08 00:32:58 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static int	is_built(t_cmd *cmd, t_data *data, t_msh *msh)
{
	if (cmd->built && (data->doors->input_door == UNLOCK
		|| data->doors->output_door == UNLOCK))
	{
		fork_built(cmd, data, msh);
		return (1);
	}
	else if (cmd->built)
	{
		g_exit_status = ex_built(cmd, data, msh);
		return (1);
	}
	return (0);
}

void	ex_loop(t_msh *msh, t_data *data)
{
	t_list	*aux_lst;
	t_cmd	*cmd;

	aux_lst = msh->lst;
	while (aux_lst)
	{
		write(1, "ENTRA\n", 6);
		cmd = ((t_cmd *) aux_lst->content);
		if (aux_lst->next || cmd->output)
			data->doors->output_door = UNLOCK;
		else
			data->doors->output_door = LOCK;
		if (cmd->input || cmd->output || cmd->del || cmd->append)
			file_redirection(data, cmd);
		if (cmd->split && !is_built(cmd, data, msh))
			ex_native(data, msh, cmd);
		else
			end_process(data);
		data->doors->input_door = UNLOCK;
		aux_lst = aux_lst->next;
		if (data->fd_input)
			close(data->fd_input);
		if (data->fd_output)
			close(data->fd_output);
	}
}

void	end_process(t_data *data)
{
	if (data->pipe_fds && data->pipe_fds[data->pipe_index])
	{
		if (data->pipe_index > 0)
			close(data->pipe_fds[data->pipe_index - 1][0]);
		close(data->pipe_fds[data->pipe_index][1]);
	}
	if (data->fd_stdin)
	{
		dup2(data->fd_stdin, STDIN_FILENO);
		close(data->fd_stdin);
	}
	if (data->fd_stdout)
	{
		dup2(data->fd_stdout, STDOUT_FILENO);
		close(data->fd_stdout);
	}
	if (data->doors->input_door)
		data->pipe_index++;
}

int	execute_cmd(t_data *data, t_msh *msh, char **split_cmd)
{
	pid_t	pid;

	pid = fork();
	data->pids[data->pipe_index] = pid;
	if (pid < 0)
	{
		write(2, "Error forking for executing a comand\n", 37);
		return (-1);
	}
	if (pid == 0)
	{
		g_exit_status = -1;
		if (data->pipe_fds && (data->doors->input_door
				|| data->doors->output_door))
			redirect(data->doors->input_door, data->doors->output_door, data);
		if (execve(data->full_rute, split_cmd, msh->env) == -1)
			return (-1);
	}
	return (0);
}
