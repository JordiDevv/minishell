/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:47:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/22 11:55:32 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int *create_pipe()
{
	int *pipe_fds;

    pipe_fds = malloc(sizeof(int *));
	if (!pipe)
	{
		perror(R "Error allocating the pipe\n" RE);
		return (-1);
	}
    
    if (pipe(pipe_fds) < 0)
    {
        perror(R "Error creating the pipe\n" RE);
        return (-1);
    }
    return (pipe_fds);
}
