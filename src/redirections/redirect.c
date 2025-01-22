/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:42 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/22 12:28:43 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int    redirect(int input, int output, int *fds)
{
    if (!fds)
    {
        printf(R "No pipe was received in a redirection.\n" RE);
        return (-1);
    }
    if (input)
        dup2(fds[0], STDIN_FILENO);
    else
        close(fds[0]);
    if (output)
        dup2(fds[1], STDOUT_FILENO);
    else
        close(fds[1]);
    return (0);
}