/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:11 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/08 17:12:29 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int    execute_cmd(int *pipe_fds, char *rute, char **split_cmd, t_msh msh)
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
            redirect(msh.doors->input_door, msh.doors->output_door, pipe_fds);
        if (execve(rute, split_cmd, msh.env) == -1)
            return (-1);
    }
    else
    {
        if (pipe_fds)
            redirect(0, 0, pipe_fds);
    }
}
