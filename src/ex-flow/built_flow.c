/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:53:57 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/09 17:00:01 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

int	ex_built(t_cmd *cmd, t_data *data, t_msh *msh)
{
	int	exit_status;

	exit_status = 0;
	if (data->pipe_fds && (data->doors->input_door
			|| data->doors->output_door))
		redirect(data->doors->input_door, data->doors->output_door, data);
	if (!ft_strncmp(cmd->built, "pwd", ft_strlen(cmd->built)))
		exit_status = ex_pwd();
	else if (!ft_strncmp(cmd->built, "echo", ft_strlen(cmd->built)))
		exit_status = ex_echo(cmd);
	else if (!ft_strncmp(cmd->built, "cd", ft_strlen(cmd->built)))
		exit_status = ex_cd(cmd, msh, data);
	else if (!ft_strncmp(cmd->built, "export", ft_strlen(cmd->built)))
		exit_status = ex_export(msh, data, cmd);
	else if (!ft_strncmp(cmd->built, "unset", ft_strlen(cmd->built)))
		exit_status = ex_unset(msh, data, cmd);
	else if (!ft_strncmp(cmd->built, "env", ft_strlen(cmd->built)))
		exit_status = ex_env(msh->env, cmd);
	else if (!ft_strncmp(cmd->built, "exit", ft_strlen(cmd->built)))
		ex_exit(data, cmd);
	return (exit_status);
}

int	fork_built(t_cmd *cmd, t_data *data, t_msh *msh)
{
	pid_t	pid;
	int		status;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	data->pids[data->pipe_index] = pid;
	if (pid < 0)
	{
		write(2, "Error forking for executing a comand\n", 37);
		return (-1);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		g_exit_status = -1;
		status = ex_built(cmd, data, msh);
		exit(status);
	}
	else
		end_process(data);
	return (0);
}
