/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:37 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/04 21:35:31 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	wait_childs(t_data *data)
{
	int	status;
	int	i;
	int	last_exit;
	int	sign;

	i = 0;
	sign = 0;
	if (data->pids)
	{
		while (data->pids[i])
		{
			waitpid(data->pids[i], &status, 0);
			if (WIFSIGNALED(status))
				sign = (128 + WTERMSIG(status));
			else if ((WIFEXITED (status)))
				last_exit = WEXITSTATUS(status);
			i++;
		}
		free(data->pids);
	}
	if (sign)
		g_exit_status = sign;
	else
		g_exit_status = last_exit;
	return (1);
}
