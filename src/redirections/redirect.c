/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/03/24 13:02:35 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int    redirect(int input, int output, t_data *data)
{
    if (!data->pipe_fds[data->pipe_index])
    {
        printf(R "No pipe was received in a redirection.\n" RE);
        return (-1);
    }
    if (input)
    {
        dup2(data->pipe_fds[data->pipe_index][0], STDIN_FILENO);
        close(data->pipe_fds[data->pipe_index][1]);
        data->pipe_index++;
    }
    else
        close(data->pipe_fds[data->pipe_index][0]);
    if (output)
        dup2(data->pipe_fds[data->pipe_index][1], STDOUT_FILENO);
    else
    {
        if (data->pipe_fds[data->pipe_index])
            close(data->pipe_fds[data->pipe_index][1]);
    }
    return (0);
}

void file_redirection(t_data *data, t_cmd *cmd)
{
    open_file(data, cmd);
    if (cmd->input)
    {
        data->fd_stdin = dup(STDIN_FILENO);
        dup2(data->fd_input, STDIN_FILENO);
        close(data->fd_input);
    }
    else if (cmd->output || cmd->append)
    {
        data->doors->output_door = unlock;
        data->fd_stdout = dup(STDOUT_FILENO);
        dup2(data->fd_stdout, STDOUT_FILENO);
        close(data->fd_stdout);
    }
    //else if (cmd->del)
    data->doors->input_door = lock;
}