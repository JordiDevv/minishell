/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:47:35 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/08 12:43:03 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if char c is an ASCII char.
Returns 1 if true.*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("isascii result = %d\n", isascii(127));
	printf("ft_isascii result = %d\n", ft_isascii(127));
}*/
