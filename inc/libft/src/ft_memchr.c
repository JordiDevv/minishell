/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:44:19 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:33:11 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s + i) == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	s[] = "teste";
	int		c;
	int		n;

	c = 'e';
	n = 6;
	printf("memchr result = %s\n", memchr(s, c + 256, n));
	printf("ft_memchr result = %s\n", ft_memchr(s, c + 256, n));
	return (0);
} */
