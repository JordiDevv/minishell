/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:54:22 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/27 02:45:42 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static int  checkout(t_cmd *cmd)
{
    DIR     *dir;

    if (cmd->split[2])
    {
        write (2, "bash: cd: too many arguments\n", 29);
        return (1);
    }
    if (cmd->split[1])
        dir = opendir(cmd->split[1]);
    if (cmd->split[1] && !dir)
    {
        perror(cmd->split[1]);
        return (1);
    }
    closedir(dir);
    return (0);
}

static int  go_home(t_cmd *cmd, t_msh *msh)
{
    char    *home;

    home = ft_find_var(msh->env, "HOME");
    if (!cmd->split[1] || cmd->split[1] && !cmd->split[1][0])
    {
        if (!home || chdir(home) < 0)
        {
            perror(home);
            return (1);
        }
        else
            return (2);
    }
    return (0);
}

static int locate_varr(char **mat, char *var)
{
    int i;

    i = 0;
    while (mat[i])
    {
        if (!strrefccmp(var, mat[i], '='))
            return (i);
        i++;
    }
    return (-1);
}

static void update_var(char *var, char *content, t_msh *msh, t_data *data)
{
    int     index;
    char    *complete_var;

    write(1, "OK\n", 3);
    complete_var = strmcat(3, 0, var, "=", content);
    index = locate_var(msh->env, complete_var);
    modify_var(msh->env, complete_var, index);
    index = locate_var(data->exported_vars, complete_var);
    modify_var(data->exported_vars, complete_var, index);
    free(complete_var);
}

int ex_cd(t_cmd *cmd, t_msh *msh, t_data *data)
{
    char    *oldpwd;
    char    *newpwd;
    int     home_flag;

    if (checkout(cmd))
        return (1);
    oldpwd = NULL;
    if (ft_find_var(msh->env, "OLDPWD"))
        oldpwd = getcwd(NULL, 0);
    home_flag = go_home(cmd, msh);
    if (home_flag == 1)
        return (1);
    else if(home_flag == 2)
        return (0);
    else if (chdir(cmd->split[1]) < 0)
    {
        perror(cmd->split[1]);
        return (1);
    }
    if (oldpwd)
    {
        update_var("OLDPWD", oldpwd, msh, data);
        free(oldpwd);
    }
    newpwd = getcwd(NULL, 0);
    if (newpwd)
        update_var("PWD", newpwd, msh, data);
    free(newpwd);
    return (0);
}

/*Debemos actualizar el built-in pwd: No accede a la variable PWD, si no que utiliza
getcwd*/