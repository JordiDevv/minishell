/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_native.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/30 12:50:56 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static bool only_one_cmd(t_msh msh, int n_cmd)
{
    t_cmd   *aux;

    aux = (t_cmd *) msh.lst->content;
    if (n_cmd == 1 && !(msh.lst->next) && !(aux->output) && !(aux->input))
        return (1);
    return (0);
}

void ex_native(t_msh msh, int n_cmd)
{
    int *pipe_fds;

    pipe_fds = NULL;
    if (!only_one_cmd(msh, n_cmd))
        pipe_fds = create_pipe();
    //execute_cmd(pipe_fds);
    wait(NULL);
}
