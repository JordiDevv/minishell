/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/03/03 13:16:53 by jsanz-bo         ###   ########.fr       */
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

void ex_native(t_data *data, t_msh msh, t_cmd *cmd)
{
    data->full_rute = valid_cmd(cmd, data);
    execute_cmd(data, msh, cmd->split);
    wait(NULL);
}
