/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:04:23 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/25 10:14:15 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void    show_export(t_data *data)
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

int valid_var(char *var)
{
    int i;

    i = 0;
    if (var[i] && var[i] == '=')
    {
        write(2, "bash: export: `", 15);
        write(2, var, ft_strlen(var));
        write(2, "': not a valid identifier\n", 26);
        return (1);
    }
    while (var[i] && var[i] != '=')
    {
        if ((var[i] != '_' && !ft_isalnum(var[i]))
            || (i == 0 && ft_isdigit(var[i])))
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

int locate_var(char **mat, char *var)
{
    int i;

    i = 0;
    while (mat[i])
    {
        if (!strccmp(mat[i], var, '='))
            return (i);
        i++;
    }
    return (-1);
}

void    modify_var(char **mat, char *var, int i)
{
    free(mat[i]);
    mat[i] = malloc((ft_strlen(var) + 1) * sizeof(char));
    if (!mat[i])
    {
        write(2, "Error allocating memory in the mat\n", 35);
        return ;
    }
    ft_strlcpy(mat[i], var, ft_strlen(var) + 1);
}

void    add_var(char ***mat, char *var)
{
    int len;

    len = mat_len(*mat);
    *mat = mat_realloc(*mat, len + 2, NULL);
    (*mat)[len] = malloc((ft_strlen(var) + 1) * sizeof(char));
    if (!(*mat)[len])
        return ;
    ft_strlcpy((*mat)[len], var, ft_strlen(var) + 1);
}

//Hay que meter en algún punto de add_var, que si no termina en '=' se concatene