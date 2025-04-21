/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:45:33 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/21 22:21:22 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void show_export(t_data *data)
{
    int i;

    i = 0;
    while (data->exported_vars[i])
    {
        write(1, "declare -x ", 11);
        write(1, data->exported_vars[i], ft_strlen(data->exported_vars[i]));
        write(1, "\n", 1);
        i++;
    }
}

static int  valid_var(char *var)
{
    int i;

    i = 0;
    while (var[i])
    {
        if (var[i] != '_' || !ft_isalnum(var[i])
            || (ft_isdigit(var[i]) && i == 0))
        {
            write(2, "bash: export: `", 15);
            write(2, var, ft_strlen(var));
            write(2, "': not a valid identifier\n", 26);
            return (1);
        }
        i++;
    }
    return (0);
}

int ex_export(t_msh *msh, t_data *data, t_cmd *cmd)
{
    int i;
    int error_flag;

    error_flag = 0;
    if (!cmd->split[1])
        show_export(data);
    else
    {
        i = 1;
        while (cmd->split[i])
        {
            if (valid_var(cmd->split[i]))
            {
                error_flag = 1;
                i++;
                continue ;
            }
            i++;
        }
    }
    return (error_flag);
    //mat_len(envp); mat_realloc(envp, mat_len(envp));

    //Deberíamos utilizar esa función para modificar envp y añadir al final la nueva variable

    /*En data deberíamos agregar una nueva matriz que almacene las variables exportadas en formato
    "declare -x MYVAR=value". Solo pueden empezar por letras o guiones bajos*/
}