/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:53:14 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/11 20:38:05 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static int	path_error(char *path)
{
	if (!path)
	{
		write(2, "Error allocating path\n", 22);
		return (1);
	}
	return (0);
}

void	get_path(t_data *data, t_msh *msh)
{
	char	*path;
	int		i;

	path = NULL;
	i = -1;
	while (msh->env[++i])
	{
		if (!ft_strncmp(msh->env[i], "PATH=", 5))
		{
			path = malloc(ft_strlen(msh->env[i]) - 4);
			if (path_error(path))
				return ;
			ft_strlcpy(path, msh->env[i] + 5, ft_strlen(msh->env[i]) - 4);
			break ;
		}
	}
	if (path)
	{
		data->split_path = ft_split(path, ':');
		free(path);
	}
	else
		write(2, "Advert: Path wasn't found\n", 26);
}
