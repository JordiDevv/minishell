/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 12:55:52 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static char	*valid_program(t_cmd *cmd, t_data *data)
{
	if (!access(cmd->full, F_OK))
		write(1, "Existe\n", 7);
	if (!access(cmd->full, X_OK))
		return (cmd->full);
	return (NULL);
}

static char	*valid_cmd(t_cmd *cmd, t_data *data)
{
	int		i;
    char    *full_rute;

	i = 0;
	while (data->split_path[i] && cmd->split)
	{
        full_rute = NULL;
		full_rute = strmcat(3, 0, data->split_path[i], "/", cmd->split[0]);
		if (!full_rute)
		{
			write(2, "Error concatenating the full rute\n", 34);
			return (NULL);
		}
		if (!access(full_rute, X_OK))
			return (full_rute);
		free(full_rute);
		i++;
	}
	if (cmd->split)
	{
		write(2, cmd->split[0], ft_strlen(cmd->split[0]));
		write(2, ": command not found\n", 21);
	}
	return (NULL);
}

void	ex_native(t_data *data, t_msh *msh, t_cmd *cmd)
{
	data->full_rute = valid_program(cmd, data);
	if (!data->full_rute)
		data->full_rute = valid_cmd(cmd, data);
	if (data->full_rute)
	{
		execute_cmd(data, msh, cmd->split);
		wait_childs();
	}
	else
		g_exit_status = 127;
	if (data->full_rute)
		free(data->full_rute);
	end_process(data);
}
