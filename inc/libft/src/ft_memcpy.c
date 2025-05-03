/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:41:44 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:33:43 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*((char *) dst + i) = *((char *) src + i);
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	void	*dst;
	void	*src;
	void	*dst_ft;
	size_t	n;
	char	src_str[] = "source";
	char	dst_str[] = "dest";

	n = 2;
	dst = &dst_str[0];
	src = &src_str[0];
	dst_ft = &dst_str[0];
	printf("dst after memcpy = %s\n", memcpy(dst, src, n));
	printf("dst after ft_memcpy = %s\n", ft_memcpy(dst_ft, src, n));
	printf("dst memcpy = %s\n", ft_memcpy(((void *)0), ((void *)0), 3));
	printf("dst after ft_memcpy = %s\n", memcpy(((void *)0), ((void *)0), 3));
}*/
