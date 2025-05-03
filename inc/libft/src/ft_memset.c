/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:45:05 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:33:58 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)(b + i)) = c;
		i++;
	}
	return ((void *) b);
}

/*int	main(void)
{
	void	*b;
	char	s[] = "hola";
	size_t	n;

	b = &s[0];
	n = 11;
	printf("memset result = %s\n", memset(b, 'c', n));
	printf("ft_memset result = %s\n", ft_memset(b, 'c', n));
	return (0);
}*/
