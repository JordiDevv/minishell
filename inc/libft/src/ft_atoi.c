/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:10:21 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/08 12:40:33 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Converts string str to int. Returns converted int*/

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	n;

	sign = 1;
	n = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

/* int	main(void)
{
	char str[] = "  \r 459822294 oo";

	printf("atoi result = %d\n", atoi(str));
	printf("ft_atoi result = %d\n", ft_atoi(str));
}
 */