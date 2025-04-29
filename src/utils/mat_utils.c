/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:19:03 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 13:08:40 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	mat_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

void	matlcpy(char **dst, char **src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = malloc((ft_strlen(src[i]) + 1) * sizeof(char));
		if (!dst[i])
		{
			free_mat(dst);
			return ;
		}
		ft_strlcpy(dst[i], src[i], ft_strlen(src[i]) + 1);
		i++;
	}
	if (size)
		dst[i] = NULL;
}

static int	re_loop(char **old_mat, char **new_mat, size_t size, char *unset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size && old_mat[i])
	{
		if (unset && !strrefccmp(old_mat[i], unset, '='))
			i++;
		if (!old_mat[i])
			break ;
		new_mat[j] = malloc((ft_strlen(old_mat[i]) + 1) * sizeof(char));
		if (!new_mat[j])
		{
			free_mat(new_mat);
			return (-1);
		}
		ft_strlcpy(new_mat[j], old_mat[i], ft_strlen(old_mat[i]) + 1);
		i++;
		j++;
	}
	return (j);
}

char	**mat_realloc(char **old_mat, size_t size, char *unset)
{
	char	**new_mat;
	int		i;

	if (!size)
		return (NULL);
	new_mat = malloc(size * sizeof(char *));
	if (!new_mat)
		return (NULL);
	i = 0;
	if (old_mat)
	{
		i = re_loop(old_mat, new_mat, size, unset);
		if (i < 0)
			return (NULL);
	}
	while (i < size)
	{
		new_mat[i] = NULL;
		i++;
	}
	free_mat(old_mat);
	return (new_mat);
}
