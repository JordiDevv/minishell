/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:43:00 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:33:30 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *) s1;
	s2_char = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*(s1_char + i) == *(s2_char + i))
			i++;
		else
			return (*(s1_char + i) - *(s2_char + i));
	}
	return (0);
}

/*int	main(void)
{
	char s1[] = "hola";
	char s2[] = "holo";

	printf("result memcmp = %d\n", memcmp(s1, s2, 6));
	printf("result ft_memcmp = %d\n", ft_memcmp(s1, s2, 6));
	return (0);
}*/
