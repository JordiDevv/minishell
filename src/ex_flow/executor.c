/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:11 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/08 12:58:03 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void ex_loop(t_msh msh, t_data *data)
{
    t_list  *aux_lst;
    t_cmd   *cmd;

    aux_lst = msh.lst;
    while (aux_lst)
    {
        cmd = ((t_cmd *) aux_lst->content);
        if (aux_lst->next)
            data->doors->output_door = unlock;
        else
            data->doors->output_door = lock;
        if (cmd->input || cmd->output || cmd->del || cmd->append)
            file_redirection(data, cmd);
        if (cmd->built)
            ex_built();
        else
            ex_native(data, msh, cmd);
        data->doors->input_door = unlock;
        aux_lst = aux_lst->next;
        if (data->fd_input)
            close(data->fd_input);
        if (data->fd_output)
            close(data->fd_output);
    }
}

void end_process(t_data *data)
{
    if (data->pipe_fds && data->pipe_fds[data->pipe_index])
        close(data->pipe_fds[data->pipe_index][1]);
    if (data->fd_stdin)
        dup2(data->fd_stdin, STDIN_FILENO);
    if (data->fd_stdout)
        dup2(data->fd_stdout, STDOUT_FILENO);
    if (data->doors->input_door)
        data->pipe_index++;
}

int execute_cmd(t_data *data, t_msh msh, char **split_cmd)
{
    pid_t   pid;
    
    pid = fork();
    if (pid < 0)
    {
        printf(R "Error forking for executing a comand.\n" RE);
        return (-1);
    }
    if (pid == 0)
    {
        if (data->pipe_fds && (data->doors->input_door 
                || data->doors->output_door))
            redirect(data->doors->input_door, data->doors->output_door, data);
        if (execve(data->full_rute, split_cmd, msh.env) == -1)
            return (-1);
    }
    else
        end_process(data);
}
