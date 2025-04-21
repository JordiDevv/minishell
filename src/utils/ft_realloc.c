/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:58:05 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/21 02:19:26 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

char    *ft_realloc(char *old_str, size_t size)
{
    char    *new_str;

    if (!size)
    {
        free(old_str);
        return (NULL);
    }
    new_str = malloc(size * sizeof(char));
    if (!new_str)
        return (NULL);
    if (old_str)
        ft_strlcpy(new_str, old_str, size);
    free(old_str);
    return (new_str);
}
