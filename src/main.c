/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:28 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/inc/libft.h"
#include "../inc/parser.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*str;

	while (1)
	{
		input = readline(ft_find_var(envp, "USER"));
		printf("input = %s\n", input);
		str = ft_expand_vars(envp, input);
		printf("expanded str = %s\n", str);
		free(str);
		if (input == NULL)
			break ;
	}
	/*str = ft_expand_vars(envp, "user = $(USER) path = $(PATH)");
	printf("expanded str = %s\n", str);*/
	return (0);
}
