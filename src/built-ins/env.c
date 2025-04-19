/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:45:59 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/20 00:00:21 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int ex_env(char **envp, t_cmd *cmd)
{
    int i;

    if (cmd->split[1])
    {
        write(2, "env: ‘", 9);
        write(2, cmd->split[1], ft_strlen(cmd->split[1]));
        write(2, "’: No such file or directory\n", 32);
        return (127);
    }
    i = 0;
    while (envp[i])
    {
        write(1, envp[i], ft_strlen(envp[i]));
        write(1, "\n", 1);
        i++;
    }
    return (0);
}