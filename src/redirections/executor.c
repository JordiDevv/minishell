/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:11 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/10 13:36:08 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int    execute_cmd(int *pipe_fds, char *rute, char **split_cmd, t_data *data)
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
        if (pipe_fds)
            redirect(data->doors->input_door, data->doors->output_door, pipe_fds);
        if (execve(rute, split_cmd, data->msh->env) == -1)
            return (-1);
    }
    else
    {
        if (pipe_fds)
            close(pipe_fds[0]);
    }
}
