/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:17:05 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/04/29 12:18:14 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*mod_s;

	len = ft_strlen(s);
	mod_s = malloc(len + 1);
	if (!mod_s)
		return (NULL);
	mod_s[len] = '\0';
	while (len-- > 0)
		mod_s[len] = f(len, s[len]);
	return (mod_s);
}
