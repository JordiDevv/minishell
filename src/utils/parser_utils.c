/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:54 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/11 19:34:42 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int	ft_del_char(char **str, int i)
{
	if (!str || !(*str))
		return (1);
	while (str[0][i])
	{
		str[0][i] = str[0][i + 1];
		i++;
	}
	return (1);
}

int	ft_count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_dbl_pipe(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i += ft_markfind(str + i);
		if (str[i] == '|')
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '|' || str[0] == '|')
			{
				write (STDOUT_FILENO,
					"minishell: syntax error near unexpected token `|'\n",
					50);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
