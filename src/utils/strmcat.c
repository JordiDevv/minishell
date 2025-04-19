/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:15:23 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/30 12:52:31 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


static void	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*strmcat(int n, int i, ...)
{
	va_list	args;
	size_t	len;
	char	*str;
	char	*str_aux;

	va_start(args, i);
	len = 0;
	while (i++ < n)
	{
		str_aux = va_arg(args, char *);
		len += ft_strlen(str_aux);
	}
	va_start(args, i);
	i = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	while (i++ < n)
	{
		str_aux = va_arg(args, char *);
		ft_strcat(str, str_aux);
	}
	va_end(args);
	return (str);
}
