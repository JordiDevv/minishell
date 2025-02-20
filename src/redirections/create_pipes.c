/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:47:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/20 15:55:57 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int count_pipes(char *line)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (line[i])
    {
        if (line[i] == '|')
            n++;
        i++;
    }
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
