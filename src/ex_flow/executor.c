/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:11 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/22 12:53:47 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void ex_loop(t_msh msh, t_data *data)
{
    t_list  *aux_lst;

    aux_lst = msh.lst;
    while (aux_lst)
    {
        if (aux_lst->next)
            data->doors->output_door = 1;
        else
            data->doors->output_door = 0;
        if (((t_cmd *) aux_lst->content)->built)
            ex_built();
        else
            ex_native(data, msh, aux_lst);
        if (!data->doors->input_door)
            data->doors->input_door = 1;
        aux_lst = aux_lst->next;
    }
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
        if (data->pipe_fds[0])
            redirect(data->doors->input_door, data->doors->output_door, data->pipe_fds[0]);
        if (execve(data->full_rute, split_cmd, msh.env) == -1)
            return (-1);
    }
    else
    {
        if (data->pipe_fds)
            close(data->pipe_fds[0][0]);
    }
}

//Los subíndices de pipe_fds no corresponden: son placeholders