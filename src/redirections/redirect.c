/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/04 01:00:32 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	redirect(int input, int output, t_data *data)
{
	if (!data->pipe_fds[data->pipe_index])
	{
		write(2, "No pipe was received in a redirection.\n", 39);
		return (-1);
	}
	if (input)
	{
		dup2(data->pipe_fds[data->pipe_index][0], STDIN_FILENO);
		close(data->pipe_fds[data->pipe_index][0]);
		close(data->pipe_fds[data->pipe_index][1]);
		data->pipe_index++;
	}
	if (output)
	{
		dup2(data->pipe_fds[data->pipe_index][1], STDOUT_FILENO);
		close(data->pipe_fds[data->pipe_index][1]);
		close(data->pipe_fds[data->pipe_index][0]);
	}
	return (0);
}

static void	input_heredoc(t_data *data, t_cmd *cmd)
{
	char	*line;

	while (1)
	{
		write(1, "> ", 2);
		line = ft_get_next_line(0);
		if (!ft_strncmp(line, cmd->del, ft_strlen(cmd->del)))
		{
			if (line)
				free(line);
			break ;
		}
		write(data->pipe_fds[0][1], line, ft_strlen(line));
		free(line);
	}
	close(data->pipe_fds[0][1]);
	data->fd_stdin = dup(STDIN_FILENO);
	dup2(data->pipe_fds[0][0], STDIN_FILENO);
	close(data->pipe_fds[0][0]);
	data->pipe_index++;
}

void	file_redirection(t_data *data, t_cmd *cmd)
{
	open_file(data, cmd);
	if (cmd->input)
	{
		data->fd_stdin = dup(STDIN_FILENO);
		dup2(data->fd_input, STDIN_FILENO);
		close(data->fd_input);
	}
	if (cmd->del)
		input_heredoc(data, cmd);
	if (cmd->output || cmd->append)
	{
		data->fd_stdout = dup(STDOUT_FILENO);
		dup2(data->fd_output, STDOUT_FILENO);
		close(data->fd_output);
	}
}
