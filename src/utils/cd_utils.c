/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:48:10 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/10 22:07:02 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int relative_args(t_cmd *cmd, t_msh *msh, t_data *data, char *oldpwd)
{
    if (!ft_strncmp(cmd->split[1], "-", ft_strlen(cmd->split[1])))
    {
        last_dir();
        return (1);
    }
    else if (!ft_strncmp(cmd->split[1], "..", ft_strlen(cmd->split[1])))
    {
        father_dir();
        return (1);
    }
    return (0);
}