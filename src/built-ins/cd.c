/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:54:22 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/26 12:56:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void    ex_cd()
{
    //char *oldpwd = getenv("PWD"); Falta malloc
    //Comprobamos con opendir() si el directorio existe o si hay permisos, y se gestiona
    //Cerramos inmediatamente el directorio con closedir(). No lo necesitamos abierto
    //Si existe, cambiamos con chdir y cerramos el directorio
    //Actualizamos la variable de entorno OLDPWD y liberamos oldpwd
    //char *newpwd = getcwd(NULL, 0); Inicializamos una variable para el nuevo pwd
    //Modificamos la variable PWD y liberamos newpwd
}