/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2024/12/09 19:52:35 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

t_command	*ft_proc_str(char *str, char **env)
{
	int			i;
	int			j;
	char		*line;
	t_command	node;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '|')
		{
			line = ft_substr(str, i, (j - i + 1));
			ft_create_node(line, &node, env);
			free(line);
			i = j + 1;
		}
		j++;
	}
	if (i < j)
	{
		line = ft_substr(str, i, (j - i + 1));
		ft_create_node(line, &node, env);
		free(line);
	}
	return (&node);
}
