/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:47:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/21 17:45:45 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int count_pipes(t_list *lst)
{
    int n;

    n = 0;
    if (((t_cmd *) (lst->content))->input)
		n++;
    while (lst->next)
    {
        lst = lst->next;
        n++;
    }
	if (((t_cmd *) (lst->content))->output)
		n++;
    return (n);
}

int *create_pipes(int n_pipes)
{
	int *pipe_fds;

    pipe_fds = malloc(sizeof(int *));
	if (!pipe)
	{
		perror(R "Error allocating the pipe\n" RE);
		return (NULL);
	}
    if (pipe(pipe_fds) < 0)
    {
        perror(R "Error creating the pipe\n" RE);
        return (NULL);
    }
    return (pipe_fds);
}
