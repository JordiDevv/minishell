/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:45:33 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/22 15:27:58 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void export_var(t_msh *msh, t_data *data, t_cmd *cmd, int i)
{
    int index;

    index = locate_var(data->exported_vars, cmd->split[i]);
    if (index >= 0)
        modify_var(data->exported_vars, cmd->split[i], index);
    else
        add_var(data->exported_vars, cmd->split[i]);
    index = locate_var(msh->env, cmd->split[i]);
    if (index >= 0)
        modify_var(msh->env, cmd->split[i], index);
    else
        add_var(msh->env, cmd->split[i]);
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
                error_flag = 1;
            else
                export_var(msh, data, cmd, i);
            i++;
        }
    }
    return (error_flag);
    //mat_len(envp); mat_realloc(envp, mat_len(envp));

    //Deberíamos utilizar esa función para modificar envp y añadir al final la nueva variable

    /*Muestra export si solo se ejecuta el comando y valida si un formato es bueno.
    ahora falta que compruebe si la variable existe en el entorno, y si existe que la modifique,
    y si no existe que la cree*/

    /*Solo se modifica si el formato es MYVAR=value, MYVAR la crea si no existe y MYVAR=value,
    en caso de no existir, la crea y le asigna ese valor*/

    /*Si haces export MYVAR, el formato con el que se verá después será: MYVAR=. Así se debe
    guardar, el manejo del valor vacío es cosa del parser*/
}