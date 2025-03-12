/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:47:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/03/12 19:52:12 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static int count_pipes(t_list *lst)
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

static int *create_pipe()
{
    int *pipe_fd;

    pipe_fd = malloc(sizeof(int) * 2);
    if (!pipe_fd)
    {
        perror(R "Error allocating a pipe\n" RE);
        //free_exit(program_data);
    }
    if (pipe(pipe_fd) < 0)
    {
        perror(R "Error creating a pipe\n" RE);
        //free "return (NULL);"
    }
    return (pipe_fd);
}

int **prepare_pipes(t_list *lst)
{
	int **pipe_fds;
    int i;
    int n_pipes;

    n_pipes = count_pipes(lst);
    if (n_pipes == 0)
        return (NULL);
    pipe_fds = malloc(sizeof(int *) * (n_pipes + 1));
	if (!pipe_fds)
	{
		perror(R "Error allocating the pipes array\n" RE);
		//free "return (NULL);"
	}
    pipe_fds[n_pipes] = NULL;
    i = n_pipes;
    while (--i > -1)
        pipe_fds[i] = create_pipe();
    return (pipe_fds);
}
