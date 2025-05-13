/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:37 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/13 10:18:01 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void	wait_loop(t_data *data, int *sign, int *last_exit)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (data->hd_flag)
		i = 1;
	while (data->pids[i])
	{
		waitpid(data->pids[i], &status, 0);
		if (WIFSIGNALED(status))
		{
			*sign = (128 + WTERMSIG(status));
			write(STDOUT_FILENO, "\n", 1);
		}
		else if ((WIFEXITED(status)))
			*last_exit = WEXITSTATUS(status);
		i++;
		signal(SIGINT, sigint_handler);
	}
}

int	wait_children(t_data *data)
{
	int	last_exit;
	int	sign;

	last_exit = 0;
	sign = 0;
	if (data->pids)
	{
		wait_loop(data, &sign, &last_exit);
		free(data->pids);
	}
	if (sign)
		g_exit_status = sign;
	else if (last_exit)
		g_exit_status = last_exit;
	else
		g_exit_status = 0;
	return (1);
}
