/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:59:28 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:35:41 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Allocates and copies the part of string s 
starting in byte start and for len bytes.*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*buff;
	size_t			slen;

	slen = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= slen)
	{
		return (ft_strdup("\0"));
	}
	else if (slen - start < len)
		len = slen - start;
	buff = (char *) malloc((len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (s[start] && i < len && len != 0)
	{
		buff[i] = s[start + i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

/* int	main(void)
{
	printf("resutl ft_substr = %s\n", ft_substr("", 1, 1));
	return (0);
} */