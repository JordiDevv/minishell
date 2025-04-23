/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:09:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/24 01:28:32 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void unset_var(t_msh *msh, t_data *data, char *var)
{
    /*Itera en todos los argumentos que se le pase: si existe en env y/o en exported, la elimina
    de las pertinente; si no existe simplemente ignora ese argumento*/
    /*Deberíamos, primero que nada comprobar si la variable existe en la matriz correspondiente
    (con "locate_var"), y, en caso de existir, hacer un mat_realloc, pero pasando, o bien el str
    con el nombre de la var, o bien el index de locate_var, para que, a la hora de copiar la
    matriz lo haga saltando esa iteración del bucle. Previamente reservando memoria = mat_len,
    sin + 1 para el NULL, porque queremos copiar una variable menos*/
}

int ex_unset(t_msh *msh, t_data *data, t_cmd *cmd)
{
    int i;
    int j;
    int error;
    
    i = 1;
    error = 0;
    while (cmd->split[i])
    {
        j = 0;
        while (cmd->split[i][j])
        {
            if ((cmd->split[i][j] != '_' && !ft_isalnum(cmd->split[i][j]))
                || (i == 0 && ft_isdigit(cmd->split[i][j])))
            {
                error = 1;
                break ;
            }
            j++;
        }
        if (!error)
            unset_var(msh, data, cmd->split[i]);
        i++;
    }
    return(error);
}
