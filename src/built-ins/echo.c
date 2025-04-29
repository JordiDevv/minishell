/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:57:27 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 16:31:33 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static int	check_flags(t_cmd *cmd, int *i)
{
	int	j;
	int	has_newline;

	has_newline = 1;
	while (cmd->split[*i])
	{
		if (cmd->split[*i][0] != '-')
			break ;
		j = 1;
		while (cmd->split[*i][j])
		{
			if (cmd->split[*i][j] != 'n')
				break ;
			j++;
		}
		if (cmd->split[*i][j])
			break ;
		(*i)++;
		has_newline = 0;
	}
	return (has_newline);
}

int	ex_echo(t_cmd *cmd)
{
	bool	has_newline;
	int		i;

	if (!cmd)
	{
		write(2, "Error: problem executing echo\n", 30);
		return (1);
	}
	i = 1;
	has_newline = check_flags(cmd, &i);
	while (cmd->split[i])
	{
		write(1, cmd->split[i], ft_strlen(cmd->split[i]));
		if (cmd->split[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (has_newline)
		write(1, "\n", 1);
	return (0);
}
