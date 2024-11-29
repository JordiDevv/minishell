/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:01:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:16 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/libft/inc/libft.h"

/*Function receives environment variables and variable to find
if found, it returns a pointer to its value. if not found, returns NULL*/
char	*ft_find_var(char **envp, char *var)
{
	char	*name;
	char	*value;
	int		i;

	name = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], var, ft_strlen(var)))
		{
			name = ft_strnstr(envp[i], var, ft_strlen(var));
			break ;
		}
		i++;
	}
	if (!name)
		return (NULL);
	value = ft_strchr(name, '=') + 1;
	return (value);
}

/*function receives environment variables, allocates space for them, 
copies them as an array of strings and returns that array*/
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
		i++;
	}
	return (env);
}

/*for testing purposes*/
/*int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**envpms;
	char	*str;

	envpms = ft_env_parser(envp);
	str = ft_find_var(envpms, "PATH=");
	return (0);
}*/
