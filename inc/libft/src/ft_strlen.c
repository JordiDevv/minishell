/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:44:14 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/28 12:30:08 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Finds length of string s and returns it*/

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
	{
		j++;
	}
	return (j);
}

/*int	main(void)
{
	printf("ft_strlen %lu\n", ft_strlen("hola"));
}*/
