/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:53:57 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/18 17:57:43 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void ex_built(t_cmd *cmd, t_data *data, char **envp)
{
    if (data->pipe_fds && (data->doors->input_door 
            || data->doors->output_door))
        redirect(data->doors->input_door, data->doors->output_door, data);
    if (!ft_strncmp(cmd->built, "pwd", ft_strlen(cmd->built)))
        ex_pwd(envp);
    else if(!ft_strncmp(cmd->built, "echo", ft_strlen(cmd->built)))
        ex_echo(cmd);
    else if(!ft_strncmp(cmd->built, "cd", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "export", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "unset", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "env", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "exit", ft_strlen(cmd->built)))
        ex_exit(data, cmd);
    else
        printf("built\n");
    end_process(data);
}
