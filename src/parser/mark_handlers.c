/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:54:44 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/11 14:15:46 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

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

void	ft_prompt_marks(t_msh *msh)
{
	char	*tmp;
	char	*aux;
	char	*next_line;

	msh->input = readline(msh->prompt);
	if (!msh->input)
		return ;
	signal(SIGINT, SIG_IGN);
	while (ft_count_marks(msh->input))
	{
		next_line = readline("<");
		if (!next_line)
		{
			free (msh->input);
			msh->input = NULL;
			return ;
		}
		aux = ft_strjoin(msh->input, "\n");
		tmp = ft_strjoin(aux, next_line);
		free (msh->input);
		free (next_line);
		free (aux);
		msh->input = tmp;
	}
	signal(SIGINT, sigint_handler);
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
