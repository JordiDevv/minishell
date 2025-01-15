/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:18:05 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/04/22 13:14:31 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len >= ft_strlen(needle))
	{
		if (*haystack == *needle)
		{
			while (haystack[i] == needle[i])
			{
				if (!(needle[i + 1]))
					return ((char *)haystack);
				i++;
			}
			i = 0;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
