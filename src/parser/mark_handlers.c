/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:54:44 by rhernand          #+#    #+#             */
<<<<<<< HEAD:src/mark_handlers.c
/*   Updated: 2025/04/26 13:46:11 by rhernand         ###   ########.fr       */
=======
/*   Updated: 2025/04/29 14:22:43 by rhernand         ###   ########.fr       */
>>>>>>> rhernand:src/parser/mark_handlers.c
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int	ft_count_marks(char *str)
{
	int		i;
	int		sgl;
	int		dbl;

	i = 0;
	sgl = 0;
	dbl = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			sgl++;
		if (str[i++] == '\"')
			dbl++;
	}
	if (((sgl % 2 == 0 && sgl != 0) || (dbl % 2 == 0 && dbl != 0))
		|| (sgl == 0 && dbl == 0))
		return (0);
	return (1);
}

void	ft_prompt_marks(t_msh *msh)
{
	char	*tmp;
	char	*aux;

	msh->input = readline(msh->prompt);
	if (!msh->input)
		return ;
	while (ft_count_marks(msh->input))
	{
		aux = ft_strjoin(msh->input, "\n");
		tmp = ft_strjoin(aux, readline("<"));
		free (msh->input);
		free (aux);
		msh->input = tmp;
	}
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
		if (str[i])
			return (i + 1);
		return (i);
	}
	return (0);
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
		if (str[i])
			return (i + 1);
		return (i);
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		if (str[i])
			return (i + 1);
		return (i);
	}
	return (0);
}
