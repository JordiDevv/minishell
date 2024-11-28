/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:01:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/28 22:17:05 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/libft/inc/libft.h"

char	**ft_env_parser(char **envp)
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	env = (char **)malloc((i + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	env[i] = NULL;
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		printf("%s\n", env[i]);
		i++;
	}
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**envpms;

	envpms = ft_env_parser(envp);
	return (0);
}