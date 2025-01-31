/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/31 17:52:05 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

char    *valid_cmd(t_cmd *cmd, t_msh *msh)
{
	int		i;
    char    *full_rute;

	i = 0;
	while (msh->split_path[i])
	{
        full_rute = NULL;
		full_rute = strmcat(3, 0, msh->split_path[i], "/", cmd->split[0]);
		if (!full_rute)
		{
			printf(R "Error concatenating the full rute" RE);
			//free_exit(program_data);
		}
		if (!access(full_rute, X_OK))
			return (full_rute);
		free(full_rute);
		i++;
	}
	printf(Y "%s: command not found\n" RE, cmd->split[0]);
}

static bool only_one_cmd(t_msh msh, int n_cmd)
{
    t_cmd   *aux;

    aux = (t_cmd *) msh.lst->content;
    if (n_cmd == 1 && !(msh.lst->next) && !(aux->output) && !(aux->input))
        return (1);
    return (0);
}

void ex_native(t_msh msh, t_cmd *cmd, int n_cmd)
{
    int     *pipe_fds;
    char    *full_rute;

    pipe_fds = NULL;
    if (!only_one_cmd(msh, n_cmd))
        pipe_fds = create_pipe();
    full_rute = valid_cmd(cmd, &msh);
    execute_cmd(pipe_fds, full_rute, cmd->split, msh.env);
    wait(NULL);
}
