/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:53:57 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 16:35:09 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

// int    built_redirect(int input, int output, t_data *data)
// {
//     if (!data->pipe_fds[data->pipe_index])
//     {
//         printf(R "No pipe was received in a redirection.\n" RE);
//         return (-1);
//     }
//     if (input)
//     {
//         dup2(data->pipe_fds[data->pipe_index][0], STDIN_FILENO);
//         //close(data->pipe_fds[data->pipe_index][1]);
//         data->pipe_index++;
//     }
//     // else
//     //     close(data->pipe_fds[data->pipe_index][0]);
//     if (output)
//         dup2(data->pipe_fds[data->pipe_index][1], STDOUT_FILENO);
//     // else
//     // {
//     //     if (data->pipe_fds[data->pipe_index])
//     //         close(data->pipe_fds[data->pipe_index][1]);
//     // }
//     return (0);
// }

// static void end_built_process(t_data *data)
// {
//     if (data->pipe_fds && data->pipe_fds[data->pipe_index])
//     {
//         if (data->pipe_index > 0)
//             close(data->pipe_fds[data->pipe_index - 1][0]);
//         close(data->pipe_fds[data->pipe_index][1]);
//     }
//     // if (data->fd_stdin)
//     //     dup2(data->fd_stdin, STDIN_FILENO);
//     if (data->fd_stdout)
//         dup2(data->fd_stdout, STDOUT_FILENO);
//     // if (data->doors->input_door)
//     //     data->pipe_index++;
// }

void	ex_built(t_cmd *cmd, t_data *data, t_msh *msh)
{
	if (data->pipe_fds && (data->doors->input_door
			|| data->doors->output_door))
		native_redirect(data->doors->input_door,
			data->doors->output_door, data);
	if (!ft_strncmp(cmd->built, "pwd", ft_strlen(cmd->built)))
		g_exit_status = ex_pwd();
	else if (!ft_strncmp(cmd->built, "echo", ft_strlen(cmd->built)))
		g_exit_status = ex_echo(cmd);
	else if (!ft_strncmp(cmd->built, "cd", ft_strlen(cmd->built)))
		g_exit_status = ex_cd(cmd, msh, data);
	else if (!ft_strncmp(cmd->built, "export", ft_strlen(cmd->built)))
		g_exit_status = ex_export(msh, data, cmd);
	else if (!ft_strncmp(cmd->built, "unset", ft_strlen(cmd->built)))
		g_exit_status = ex_unset(msh, data, cmd);
	else if (!ft_strncmp(cmd->built, "env", ft_strlen(cmd->built)))
		g_exit_status = ex_env(msh->env, cmd);
	else if (!ft_strncmp(cmd->built, "exit", ft_strlen(cmd->built)))
		ex_exit(data, cmd);
	end_process(data);
}
