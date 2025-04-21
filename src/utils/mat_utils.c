/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:19:03 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/21 02:19:35 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int mat_len(char **mat)
{
    int i;

    i = 0;
    while (mat[i])
        i++;
    return (i);
}

void    free_mat(char **mat)
{
    int i;

    i = 0;
    while (mat[i])
        free(mat[i++]);
    free(mat);
}

static int reallocating_mat(char ***old_mat, char ***new_mat, int *i)
{
    (*new_mat)[*i] = malloc((ft_strlen((*old_mat)[*i]) + 1) * sizeof(char));
    if (!(*new_mat)[*i])
    {
        free_mat((*new_mat));
        return (1);
    }
    ft_strlcpy((*new_mat)[*i], (*old_mat)[*i], ft_strlen((*old_mat)[*i]) + 1);
    (*i)++;
    return (0);
}

char    **mat_realloc(char **old_mat, size_t size)
{
    char    **new_mat;
    size_t  i;

    if (!size)
        return (NULL);
    new_mat = malloc(size * sizeof(char *));
    if (!new_mat)
        return (NULL);
    i = 0;
    if (old_mat)
    {
        while (i < size && old_mat[i])
        {
            if (reallocating_mat(&old_mat, &new_mat, &i))
                return (NULL);
        }
    }
    while (i < size)
        new_mat[i] = NULL;
    free_mat(old_mat);
    return (new_mat);
}
