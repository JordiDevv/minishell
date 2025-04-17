/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:57:27 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/17 18:16:47 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

void	ex_echo(t_cmd *cmd)
{
	bool	has_newline;
	int		i;

	if (!cmd)
	{
		printf(Y "Error: problem executing echo" RE);
		return ;
	}
	i = 1;
	has_newline = true;
	if (cmd->split[1] && !ft_strncmp(cmd->split[1], "-n", 2))
	{
		i = 2;
		has_newline = false;
	}
	while (cmd->split[i])
	{
		printf("%s", cmd->split[i]);
		if (cmd->split[i + 1])
			printf(" ");
		i++;
	}
	if (has_newline)
		printf("\n");
}
