/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:06:04 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:35:33 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Locates c char in s string from end to beginning. If '\0' is passed
it locates end of string. Returns pointer to char found*/

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c % 256)
			return (&s[i]);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	s[] = "teste";
	int		c;

	c = 'x';
	printf("strrchr result = %s\n", strrchr(s, c));
	printf("ft_strrchr result = %s\n", ft_strrchr(s, c));
	return (0);
}*/
