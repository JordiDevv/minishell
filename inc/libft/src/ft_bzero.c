/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:16:20 by rhernand          #+#    #+#             */
/*   Updated: 2024/10/18 09:52:47 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)(s + i)) = '\0';
		i ++;
	}
}

/*int	main(void)
{
	char	str[] = "HelloWorld";
	void	*ptr;
	ptr = &str[0];
	printf("string before = %s\n", ptr);
	ft_bzero(ptr, 5);
	printf("string after = %s\n", ptr);
	printf("string after = %s\n", ptr + 1);
	printf("string after = %s\n", ptr + 2);
	printf("string after = %s\n", ptr + 3);
	printf("string after = %s\n", ptr + 4);
	printf("string after = %s\n", ptr + 5);
}*/	
