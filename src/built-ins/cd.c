/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:54:22 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/26 19:09:23 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void    ex_cd(t_cmd *cmd)
{
    int     go_home;
    char    *oldpwd;

    go_home = 0;
    if (cmd->split[2])
    {
        write (2, "bash: cd: too many arguments\n", 29);
        return (1);
    }
    if (!cmd->split[1] || cmd->split[1] && !cmd->split[1][0])
        go_home = 1;
    oldpwd = getenv("PWD"); //Hay que seguir investigando qué sucede en los casos nulos
    /*Debemos actualizar el built-in pwd: No accede a la variable PWD, si no que utiliza
    getcwd*/
    
    //Comprobamos con opendir() si el directorio existe o si hay permisos, y se gestiona
    //Cerramos inmediatamente el directorio con closedir(). No lo necesitamos abierto
    //Si existe, cambiamos con chdir y cerramos el directorio
    //Actualizamos la variable de entorno OLDPWD y liberamos oldpwd
    //char *newpwd = getcwd(NULL, 0); Inicializamos una variable para el nuevo pwd
    //Modificamos la variable PWD y liberamos newpwd
}