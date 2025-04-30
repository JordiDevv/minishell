/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:44:10 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:35:08 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Copies dstsize bytes of src in dst.
Returns length of src.*/

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (dstsize != 0 && i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	if (i < dstsize)
		dest[i] = '\0';
	while (src[i])
		++i;
	return (i);
}

/* int	main(void)
{
	char 	str[] = "Hello";
	char 	src[] = "World";
	
	printf("result ft_strlcpy = %s\n", ft_strlcpy(str, src, 10));
} */