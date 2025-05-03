/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:20:59 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/08 12:43:52 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if char c is a printable char.
Returns 1 if true.*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
