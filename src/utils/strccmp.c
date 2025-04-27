/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strccmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:40 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/27 13:43:27 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int strrefccmp(char *ref, char *cmp, char c)
{
    int i;

    i = 0;
    while (ref[i] && cmp[i] && ref[i] == cmp[i])
        i++;
    if ((!ref[i] && !cmp[i]) || (!cmp[i] && ref[i] == c))
        return (0);
    return (1);
}

int strccmp(char *s1, char *s2, char c)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
    {
        if (s1[i] == c && s2[i] == c)
            return (0);
        if (!s1[i + 1] && s2[i + 1] == c)
            return (0);
        if (s1[i + 1] == c && !s2[i + 1])
            return (0);
        i++;
    }
    if (!s1[i] && !s2[i])
        return (0);
    return (1);
}

// int strccmp(char *s1, char *s2, char c)
// {
//     int i;

//     i = 0;
//     while (s1[i] && s2[i] && s1[i] == s2[i])
//     {
//         if (s1[i] == c && s2[i] == c)
//             return (0);
//         i++;
//     }
//     return (1);
// }
