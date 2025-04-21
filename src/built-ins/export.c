/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:45:33 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/21 02:17:40 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int ex_export(char **envp)
{
    //mat_len(envp); mat_realloc(envp, mat_len(envp));

    //Deberíamos utilizar esa función para modificar envp y añadir al final la nueva variable

    /*En data deberíamos agregar una nueva matriz que almacene las variables exportadas en formato
    "declare -x MYVAR=value". Solo pueden empezar por letras o guiones bajos*/

    //Tenemos que aclarar con que debería empezar esa matriz
}