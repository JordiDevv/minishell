/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/25 15:58:46 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void unset_var(char ***env, char ***export, char *var)
{
    int i;

    i = 0;
    while ((*export)[i])
    {
        if (!strrefccmp((*export)[i], var, '='))
        {
            *export = mat_realloc(*export, mat_len(*export), var);
            break ;
        }
        i++;
    }
    while ((*env)[i])
    {
        if (!strrefccmp((*env)[i], var, '='))
        {
            *env = mat_realloc(*env, mat_len(*env), var);
            break ;
        }
        i++;
    }
}

static int valid_unset(t_cmd *cmd, int i, int *error_flag)
{
    int j;
    int return_code;

    j = 0;
    while (cmd->split[i][j])
    {
        if ((cmd->split[i][j] != '_' && !ft_isalnum(cmd->split[i][j]))
            || (j == 0 && ft_isdigit(cmd->split[i][j])))
        {
            *error_flag = 1;
            if (!cmd->split[i][j + 1] && cmd->split[i][j] == '=')
                return_code = 0;
            else
                return_code = 1;
            break ;
        }
        j++;
    }
    return (return_code);
}

int ex_unset(t_msh *msh, t_data *data, t_cmd *cmd)
{
    int i;
    int error_flag;
    int return_code;
    
    i = 1;
    error_flag = 0;
    return_code = 0;
    while (cmd->split[i])
    {
        valid_unset(cmd, i, &return_code);
        if (!error_flag)
            unset_var(&(msh->env), &(data->exported_vars), cmd->split[i]);
        i++;
        error_flag = 0;
    }
    return(return_code);
}
