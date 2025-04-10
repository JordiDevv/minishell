/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:53:57 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/10 16:02:35 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void ex_built(t_cmd *cmd, char **envp)
{
    if (!ft_strncmp(cmd->built, "pwd", ft_strlen(cmd->built)))
        ex_pwd(envp);
    else if(!ft_strncmp(cmd->built, "echo", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "cd", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "export", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "unset", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "env", ft_strlen(cmd->built)))
        printf("built\n");
    else if(!ft_strncmp(cmd->built, "exit", ft_strlen(cmd->built)))
        printf("built\n");
    else
        printf("built\n");
}
