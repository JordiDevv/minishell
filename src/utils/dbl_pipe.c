/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:54 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/09 16:27:33 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

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
