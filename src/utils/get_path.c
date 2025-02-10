/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:53:14 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/10 12:55:46 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

void	get_path(t_data *program_data)
{
	char	*path;
    int     i;

	path = NULL;
    i = -1;
	while (program_data->msh->env[++i])
	{
		if (!ft_strncmp(program_data->msh->env[i], "PATH=", 5))
		{
			path = malloc(ft_strlen(program_data->msh->env[i]) - 4);
			if (!path)
			{
				perror(R "Error allocating path\n" RE);
				//free_exit(program_data);
			}
			ft_strlcpy(path, program_data->msh->env[i] + 5, 
				ft_strlen(program_data->msh->env[i]) - 4);
		}
	}
	if (!path)
	{
		printf(R "Error: Path wasn't found\n" RE);
		//free_exit(msh);
	}
	program_data->split_path = ft_split(path, ':');
	free(path);
}
