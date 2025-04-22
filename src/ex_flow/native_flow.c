/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/22 13:55:03 by rhernand         ###   ########.fr       */
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
	write(2, cmd->split[0], ft_strlen(cmd->split[0]));
	write(2, ": command not found\n", 21);
	return (NULL);
}

void	ex_native(t_data *data, t_msh *msh, t_cmd *cmd)
{
	data->full_rute = valid_cmd(cmd, data);
	if (data->full_rute)
	{
		execute_cmd(data, msh, cmd->split);
		wait (&data->exit_code);
		if (WIFEXITED (data->exit_code))
			g_exit_status = WEXITSTATUS(data->exit_code);
		if (WIFSIGNALED (data->exit_code))
			g_exit_status = (128 + WTERMSIG(data->exit_code));
	}
	else
		g_exit_status = 127;
	if (data->full_rute)
		free(data->full_rute);
	end_process(data);
}
