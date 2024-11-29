/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:13 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/inc/libft.h"
#include "../inc/parser.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	while (1)
	{
		input = readline(ft_find_var(envp, "USER="));
		printf("input = %s\n", input);
		if (input == NULL)
			break ;
	}
	return (0);
}