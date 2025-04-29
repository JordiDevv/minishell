/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:04:01 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/29 16:52:07 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

char	*ft_dup_var(char **env, char *var)
{
	char	*tmp;

	tmp = ft_strdup(ft_find_var(env, var));
	if (!tmp)
		return ("\0");
	return (tmp);
}

char	*ft_concat_prompt(char **env, char *pwd)
{
	char	*str;
	char	*usr;
	t_size	size;

	usr = ft_find_var(env, "USER=") - 1;
	if (!*usr)
		return ("\0");
	size = ft_strlen(pwd) + ft_strlen(usr) + 14;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return ("\0");
	if (!ft_strlcpy(str, usr, size) || !ft_strlcat(str, "@minishell:", size)
		|| !ft_strlcat(str, pwd, size) || !ft_strlcat(str, "$ ", size))
		return ("\0");
	str[size] = '\0';
	return (str);
}

/*ft_prompt recieves environment, finds PWD, HOME and USER,
finds if the current dir contains HOME dir and creates
a str that simulates bash prompt*/

char	*ft_prompt(char **env)
{
	char	*str;
	char	*pwd;
	char	*tmp;
	char	*home;

	tmp = ft_dup_var(env, "PWD");
	home = ft_find_var(env, "HOME");
	pwd = tmp;
	if (ft_strnstr(pwd, home, ft_strlen(home)) && *pwd && *home)
	{
		pwd += ft_strlen(home) - 1;
		pwd[0] = '~';
	}
	str = ft_concat_prompt(env, pwd);
	if (tmp && *tmp != '\0')
		free(tmp);
	return (str);
}
