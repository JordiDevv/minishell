/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:45:33 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/11 20:33:59 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void	export_var(t_msh *msh, t_data *data, t_cmd *cmd, int i)
{
	int	index;

	index = locate_var(data->exported_vars, cmd->split[i]);
	if (index >= 0)
		modify_var(data->exported_vars, cmd->split[i], index);
	else
		add_var(&(data->exported_vars), cmd->split[i]);
	index = locate_var(msh->env, cmd->split[i]);
	if (index >= 0)
		modify_var(msh->env, cmd->split[i], index);
	else
		add_var(&(msh->env), cmd->split[i]);
}

int	ex_export(t_msh *msh, t_data *data, t_cmd *cmd)
{
	int	i;
	int	error_flag;

	error_flag = 0;
	if (!cmd->split[1])
		show_export(data);
	else
	{
		i = 1;
		while (cmd->split[i])
		{
			if (valid_var(cmd->split[i]))
				error_flag = 1;
			else
				export_var(msh, data, cmd, i);
			i++;
		}
	}
	return (error_flag);
}
