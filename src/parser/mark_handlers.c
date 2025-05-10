/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:54:44 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/10 12:52:07 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/executor.h"

int	ft_markfind_double(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		return (i);
	}
	return (0);
}

int	ft_markfind_single(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		return (i);
	}
	return (0);
}

int	ft_count_marks(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i += ft_markfind_double(str + i);
		if (!str[i])
			return (1);
		i += ft_markfind_single(str + i);
		if (!str[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_sub_line(t_msh *msh, int *pipe_fd)
{
	char	*next_line;
	char	*aux;

	signal(SIGINT, SIG_DFL);
	close (pipe_fd[0]);
	msh->input = readline(msh->prompt);
	if (!msh->input)
		exit (EXIT_FAILURE);
	while (ft_count_marks(msh->input))
	{
		next_line = readline("<");
		if (!next_line)
		{
			free (msh->input);
			msh->input = NULL;
			exit (EXIT_FAILURE);
		}
		aux = ft_strjoin(msh->input, next_line);
		free (msh->input);
		free (next_line);
		msh->input = aux;
	}
	write(pipe_fd[1], msh->input, ft_strlen(msh->input));
	close (pipe_fd[1]);
	free(msh->input);
	exit (EXIT_SUCCESS);
}

void	ft_prompt_marks(t_msh *msh)
{
	pid_t	pid;
	int		pipe_fd[2];
	char	*aux;
	char	*tmp;

	msh->input = NULL;
	tmp = NULL;
	pipe(pipe_fd);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		ft_sub_line(msh, pipe_fd);
	else
	{
		signal(SIGINT, sigint_handler);
		waitpid(pid, NULL, 0);
		close(pipe_fd[1]);
		while (1)
		{
			aux = ft_get_next_line(pipe_fd[0]);
			if (!aux)
				break ;
			tmp = ft_strjoin(msh->input, aux);
			free (aux);
			free (msh->input);
			msh->input = tmp;
		}
		close(pipe_fd[0]);
	}
}

int	ft_markfind(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		return (i);
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		return (i);
	}
	return (0);
}
