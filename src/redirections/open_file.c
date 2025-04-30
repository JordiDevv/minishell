/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:50:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 12:06:58 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void	open_file(t_data *data, t_cmd *cmd)
{
	if (cmd->input && access(cmd->input, F_OK))
	{
		printf(Y "-bash: %s: %s\n" RE, cmd->input, strerror(errno));
	}
	else
	{
		if (cmd->input)
			data->fd_input = open(cmd->input, O_RDONLY);
		if (cmd->output)
			data->fd_output = open(cmd->output, O_WRONLY | O_CREAT
					| O_TRUNC, S_IRUSR | S_IWUSR);
		else if (cmd->append)
			data->fd_output = open(cmd->append, O_WRONLY | O_CREAT
					| O_APPEND, S_IRUSR | S_IWUSR);
	}
	if ((data->fd_input && data->fd_input < 0)
		|| (data->fd_output && data->fd_output < 0))
	{
		perror(R "Error opening, or creating, one redirection file\n" RE);
	}
}
