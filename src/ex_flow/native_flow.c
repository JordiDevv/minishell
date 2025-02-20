/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/20 15:52:14 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static char    *valid_cmd(t_cmd *cmd, t_data *data)
{
	int		i;
    char    *full_rute;

	i = 0;
	while (data->split_path[i])
	{
        full_rute = NULL;
		full_rute = strmcat(3, 0, data->split_path[i], "/", cmd->split[0]);
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

/*static bool only_one_cmd(t_msh *msh, int n_cmd)
{
    t_cmd   *aux;

    aux = (t_cmd *) msh->lst->content;
    if (n_cmd == 1 && !(msh->lst->next) && !(aux->output) && !(aux->input))
        return (1);
    return (0);
}*/

void ex_native(t_data *data, t_msh msh, t_list *aux_lst, int n_cmd)
{
    t_cmd	*cmd;

	cmd = ((t_cmd *) aux_lst->content);
    data->pipe_fds = NULL;
    if (/*!only_one_cmd(program_data->msh, n_cmd)*/data->doors->input_door || data->doors->output_door)
	{
		write(1, "Llega\n", 6);
        data->pipe_fds = create_pipes(data->n_pipes);
	}
    data->full_rute = valid_cmd(cmd, data);
    execute_cmd(data, msh, cmd->split);
    wait(NULL);
}
