/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:19:38 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/08 12:43:23 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if char c is a digit.
Returns 1 if true*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
