/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/11 11:32:57 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/inc/libft.h"
#include "../inc/parser.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*str;
	char	**env;

	env = ft_env_parser(envp);
	while (1)
	{
		input = readline(ft_find_var(env, "USER"));
		printf("input = %s\n", input);
		str = ft_expand_vars(env, input);
		printf("expanded str = %s\n", str);
		str = ft_expand_home(env, str);
		//ft_proc_str(str, envp);
		free(str);
		if (input == NULL)
			break ;
	}
	ft_free_env(env);
	return (0);
}
