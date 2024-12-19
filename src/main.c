/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2024/12/19 13:13:40 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/inc/libft.h"
#include "../inc/parser.h"
#include "../inc/executor.h"

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
		ft_proc_str(str, envp);
		free(str);
		if (input == NULL)
			break ;
	}
	ex_pwd(env);
	ft_free_env(env);
	return (0);
}
