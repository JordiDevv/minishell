/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:41:44 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:33:51 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *) dst;
	s = (const char *) src;
	if (src == dst)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		while (len--)
			*(d++) = *(s++);
	}
	return (dst);
}

/*
int	main(void)
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
