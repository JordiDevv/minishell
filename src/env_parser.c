/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:01:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/28 21:49:16 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char **ft_env_parser(char **envp)
{
	int i;
	char **env;

	i = 0;
	while (envp[i])
		i++;
	env = 
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	char**envpms;

	envpms = ft_env_parser(envp);
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	envpms = (char **)malloc(( i + 1) * sizeof(char *));
	if 

}