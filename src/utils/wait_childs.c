/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:37 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 13:10:01 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	wait_childs(void)
{
	int	status;

	wait (&status);
	if (WIFEXITED (status))
		g_exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED (status))
		g_exit_status = (128 + WTERMSIG(status));
	return (1);
}
