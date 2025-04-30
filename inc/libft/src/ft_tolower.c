/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:48:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:36:01 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Converts char c to lowercase if it finds uppercase.
Returns converted char (as int)*/

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

/*int	main(void)
{
	int	c;

	c = 'A';
	printf("tolower result = %c\n", tolower(c));
	printf("ft_tolower result = %c\n", ft_tolower(c));
	return (0);
}*/
