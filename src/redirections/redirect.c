/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/11 20:58:33 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	redirect(int input, int output, t_data *data)
{
	if (!data->pipe_fds[data->pipe_index] && !data->hd_flag)
	{
		write(2, "No pipe was received in a redirection.\n", 39);
		return (-1);
	}
	if (input && !data->fd_input)
	{
		dup2(data->pipe_fds[data->pipe_index][0], STDIN_FILENO);
		close(data->pipe_fds[data->pipe_index][0]);
		close(data->pipe_fds[data->pipe_index][1]);
		data->pipe_index++;
	}
	if (output && !data->fd_output)
	{
		dup2(data->pipe_fds[data->pipe_index][1], STDOUT_FILENO);
		close(data->pipe_fds[data->pipe_index][1]);
		close(data->pipe_fds[data->pipe_index][0]);
	}
	return (0);
}

static void	heredoc_loop(t_data *data, t_cmd *cmd)
{
	char	*line;

	while (1)
	{
		write(1, "> ", 2);
		line = ft_get_next_line(0);
		if (!line)
		{
			write (1,
				"MSH: warning: here-document delimited by end-of-file\n",
				54);
			break ;
		}
		if (!ft_strncmp(line, cmd->del, ft_strlen(cmd->del)))
		{
			if (line)
				free(line);
			break ;
		}
		write(data->pipe_fds[data->pipe_index][1], line, ft_strlen(line));
		free(line);
	}
}

static void	close_heredoc(t_data *data)
{
	int	status;

	close(data->pipe_fds[data->pipe_index][1]);
	data->fd_stdin = dup(STDIN_FILENO);
	dup2(data->pipe_fds[data->pipe_index][0], STDIN_FILENO);
	close(data->pipe_fds[data->pipe_index][0]);
	waitpid(data->pids[data->pipe_index], &status, 0);
	if (WIFSIGNALED(status))
	{
		g_exit_status = (128 + WTERMSIG(status));
		write(STDOUT_FILENO, "\n", 1);
	}
	else if ((WIFEXITED(status)))
		g_exit_status = WEXITSTATUS(status);
	signal(SIGINT, sigint_handler);
	data->hd_flag = 1;
	data->pipe_index++;
}

static void	input_heredoc(t_data *data, t_cmd *cmd)
{
	signal(SIGINT, SIG_IGN);
	data->pids[data->pipe_index] = fork();
	if (data->pids[data->pipe_index] < 0)
	{
		write(2, "Error forking for executing a command\n", 38);
		return ;
	}
	else if (data->pids[data->pipe_index] == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		g_exit_status = -1;
		close(data->pipe_fds[data->pipe_index][0]);
		heredoc_loop(data, cmd);
		close(data->pipe_fds[data->pipe_index][1]);
		exit(0);
	}
	else
		close_heredoc(data);
}

void	file_redirection(t_data *data, t_cmd *cmd)
{
	open_file(data, cmd);
	if (cmd->del)
		input_heredoc(data, cmd);
	if (cmd->input)
	{
		data->fd_stdin = dup(STDIN_FILENO);
		dup2(data->fd_input, STDIN_FILENO);
		close(data->fd_input);
	}
	if (cmd->output || cmd->append)
	{
		data->fd_stdout = dup(STDOUT_FILENO);
		dup2(data->fd_output, STDOUT_FILENO);
		close(data->fd_output);
	}
}
