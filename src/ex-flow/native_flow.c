/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:00 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/13 16:17:00 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static char	*valid_program(t_cmd *cmd, t_data *data)
{
	char	*full_rute;

	full_rute = ft_strtrim(cmd->split[0], " \n\t\v\f\r");
	if (!access(full_rute, X_OK))
	{
		data->abs_flag = 1;
		return (full_rute);
	}
	if (full_rute)
		free(full_rute);
	return (NULL);
}

static char	*valid_cmd(t_cmd *cmd, t_data *data)
{
	int		i;
	char	*full_rute;

	i = 0;
	while (data->split_path && data->split_path[i] && cmd->split)
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
	if (!cmd->full)
		return ;
	data->full_rute = valid_program(cmd, data);
	if (!data->full_rute)
		data->full_rute = valid_cmd(cmd, data);
	if (data->full_rute)
	{
		execute_cmd(data, msh, cmd->split);
		end_process(data);
	}
	else
		g_exit_status = 127;
	if (data->full_rute)
		free(data->full_rute);
}
