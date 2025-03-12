/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/03/12 23:11:14 by jsanz-bo         ###   ########.fr       */
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
    //Creo que aquí iría el open_file y la redirección a ficheros
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
