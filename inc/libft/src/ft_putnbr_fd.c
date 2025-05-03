/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:58:24 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:34:10 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_rec(int n, int fd)
{
	char	c;

	if (n > -1 && n < 1)
		return ;
	if (n < 0)
		c = -(n % 10) + 48;
	else
		c = (n % 10) + 48;
	ft_rec(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_rec(n, fd);
}

/* int	main(void)
{
	ft_putnbr_fd(0, 2);
	return (0);
} */
