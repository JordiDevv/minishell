/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:55:35 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/24 01:41:53 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	aux_free(t_data *program_data)
{
	free(program_data->full_rute);
	program_data->full_rute = NULL;
}

static void	prepare_aux(t_data *program_data, char *cmd)
{
	if (program_data->full_rute)
		free(program_data->full_rute);
	if (program_data->split_cmd)
		free_mat(program_data->split_cmd);
	program_data->split_cmd = ft_split(cmd, ' ');
	if (!program_data->split_cmd)
	{
		ft_printf(R "Error spliting the comand" RE);
		free_exit(program_data);
	}
}

void	valid_cmd(char *cmd, t_data *program_data)
{
	int		i;

	i = 0;
	prepare_aux(program_data, cmd);
	while (program_data->path_mat[i])
	{
		program_data->full_rute = strmcat(3, 0, program_data->path_mat[i], "/",
				program_data->split_cmd[0]);
		if (!program_data->full_rute)
		{
			ft_printf(R "Error concatenating the full rute" RE);
			free_exit(program_data);
		}
		if (!access(program_data->full_rute, X_OK))
		{
			if (program_data->step == 1)
				program_data->cmd1 = 1;
			else if (program_data->step == 2)
				program_data->cmd2 = 1;
			return ;
		}
		aux_free(program_data);
		i++;
	}
	ft_printf(Y "%s: command not found\n" RE, program_data->split_cmd[0]);
}
