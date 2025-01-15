/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:11:35 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/05/09 17:13:32 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strparr(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free_split(char **a)
{
	size_t	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}

static char	**ft_do_split(char **arr, char const *s, char c, size_t i)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			end = start;
			while (s[end] && s[end] != c)
				end++;
			arr[i++] = ft_substr(s, start, end - start);
			if (!arr[i - 1])
			{
				ft_free_split(arr);
				return (NULL);
			}
			start = end;
		}
		if (s[start])
			start++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_strparr(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_do_split(arr, s, c, i);
	return (arr);
}
