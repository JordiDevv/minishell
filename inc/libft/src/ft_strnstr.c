/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:15:19 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/30 10:02:41 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Finds string needle in string haystack whitin len bytes.
returns pointer to first byte of needle in haystack*/

char	*ft_strnstr(char *haystack, char *needle, t_size len)
{
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j]
				&& haystack[i + j] && i + j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return (&haystack[i]);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	haystack[] = "donde lo tengo que encontrar";
	char	needle[] = "tengo";

	printf("strnstr result = %s\n", strnstr(haystack, needle, 2));
	printf("ft_strnstr result = %s\n", ft_strnstr(haystack, needle, 2));
	return (0);
}*/
