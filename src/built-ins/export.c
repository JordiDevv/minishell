/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:45:33 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/21 13:36:21 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int ex_export(t_msh *msh, t_data *data)
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
    return (0);
    //mat_len(envp); mat_realloc(envp, mat_len(envp));

    //Deberíamos utilizar esa función para modificar envp y añadir al final la nueva variable

    /*En data deberíamos agregar una nueva matriz que almacene las variables exportadas en formato
    "declare -x MYVAR=value". Solo pueden empezar por letras o guiones bajos*/

    //Tenemos que aclarar con que debería empezar esa matriz
}