/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:01:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:05 by rhernand         ###   ########.fr       */
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
	var = ft_strjoin(var, "=");
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
	free (var);
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

/*Receives str with markers pointing to environment var start (i) and end (j). 
Finds var in envp and returns new string copying var value in the right place*/
char	*ft_subst_dolar(char **envp, char *str, int i, int j)
{
	char	*var;
	char	*env;
	char	*tmp;
	int		length;

	var = ft_substr(str, i, j);
	env = ft_find_var(envp, var);
	if (!env)
		return (NULL);
	length = ft_strlen(str) + ft_strlen(env) - (j - i) - 2;
	tmp = malloc (length * sizeof(char));
	if (!tmp)
		return (NULL);
	if (!ft_strlcpy(tmp, str, i - 1) || !ft_strlcat(tmp, env, length) \
			|| !ft_strlcat(tmp, (str + (i + j + 1)), length))
		return (NULL);
	tmp[length] = '\0';
	free(var);
	return (tmp);
}

/*Identifies $ signs in str, expands with correct env var.
returns string with all vars expanded. */
char	*ft_expand_vars(char **envp, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '(')
		{
			i++;
			j = 0;
			while (str[i + j] != ')' && str[i + j])
				j++;
			if (str[i + j])
				str = ft_subst_dolar(envp, str, i + 1, j - 1);
		}
		i++;
	}
	return (str);
 }

/*for testing purposes*/
/*int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**envpms;
	char	*str;

	envpms = ft_env_parser(envp);
	str = ft_expand_vars(envpms, "this is path = $(PATH)");
	printf("%s\n", str);
	return (0);
}*/
