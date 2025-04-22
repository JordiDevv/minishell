/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:45:33 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/22 11:19:10 by jsanz-bo         ###   ########.fr       */
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
        if (var[i] != '_' && !ft_isalnum(var[i])
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

static void modify_var(char **mat, char *var)
{
    int i;

    i = 0;
    if (ft_strchr(var, '='))
    {
        while (mat[i])
        {
            if (!strccmp(mat[i], var, '='))
            {
                free(mat[i]);
                mat[i] = malloc((ft_strlen(var) + 1) * sizeof(char));
                if (!mat[i])
                {
                    write(2, "Error allocating memory int the mat\n", 36);
                    return ;
                }
                ft_strlcpy(mat[i], var, ft_strlen(var) + 1);
                return ;
            }
            i++;
        }
    }
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
            {
                if (ft_find_var(msh->env, cmd->split[i]))
                    modify_var(msh->env, cmd->split[i]);
                else
                    add_var();
            }
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