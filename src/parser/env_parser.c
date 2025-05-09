/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:01:08 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/09 14:36:26 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

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
		return ("\0");
	value = name + ft_strlen(var) + 1;
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
	if (!var)
		return (NULL);
	env = ft_find_var(envp, var);
	if (!env)
	{
		free(var);
		return (str);
	}
	length = ft_strlen(str) + ft_strlen(env) - (j - i);
	tmp = malloc (length * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	if (!ft_strlcpy(tmp, str, i) || !ft_strlcat(tmp, env, length)
		|| !ft_strlcat(tmp, (str + (i + j)), length))
		return (NULL);
	tmp[length] = '\0';
	free(var);
	return (tmp);
}

char	*ft_subst_exit(char *str, int i)
{
	char	*tmp;
	int		length;
	char	*exit;

	exit = ft_itoa(g_exit_status);
	length = ft_strlen(str) + ft_strlen(exit) - 1;
	tmp = malloc (length * sizeof(char));
	if (!tmp)
		return (NULL);
	if (!ft_strlcpy(tmp, str, i) || !ft_strlcat(tmp, exit, length)
		|| !ft_strlcat(tmp, (str + (i + 1)), length))
		return (NULL);
	tmp[length] = '\0';
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
		i += ft_markfind_single(str + i);
		if (str[i] == '$')
		{
			j = 0;
			if (str[i++ + 1] == '?')
				str = ft_subst_exit(str, i);
			else
			{
				while (ft_isalnum(str[i + j]))
					j++;
				if (!j)
					continue ;
				str = ft_subst_dolar(envp, str, i, j);
				i = i + j - 1;
			}
		}
		i++;
	}
	return (str);
}
