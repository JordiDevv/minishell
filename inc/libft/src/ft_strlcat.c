/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:32:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:35:04 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Concatenates dstsize bytes of string src in string dst.
Returns size of src + dstsize if dst is not big enough.
Otherwise returns lenght of src + dst*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	dst_count;
	size_t	src_count;

	dst_size = ft_strlen(dst);
	dst_count = dst_size;
	src_count = 0;
	if (dst_count >= dstsize)
		return (dstsize + ft_strlen(src));
	while (dst_count < dstsize - 1 && src[src_count])
		dst[dst_count++] = src[src_count++];
	dst[dst_count] = '\0';
	return (ft_strlen(src) + dst_size);
}

/*int	main(void)
{
	char	src[] = "hola";
	char	dst[] = "adiossss";
	char	buffer[15];
	char	buffer_ft[15];

	strlcpy(buffer, dst, 12);
	ft_strlcpy(buffer_ft, dst, 12);
	printf("strlcat = %lu\n", strlcat(buffer, src, 12));
	printf("dst strlcat = %s\n", buffer);
	printf("src strlcat = %s\n", src);
	ft_strlcpy(buffer_ft, dst, 12);
	printf("ft_strlcat = %lu\n", ft_strlcat(buffer_ft, src, 12));
	printf("dst strlcat = %s\n", buffer_ft);
	strlcat("pqrstuvwxyz", "abcd", 20);
}*/
