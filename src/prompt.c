/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:04:01 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/28 12:13:39 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

/*ft_prompt recieves environment, finds PWD, HOME and USER,
finds if the current dir contains HOME dir and creates
a str that simulates bash prompt*/

char	*ft_prompt(char **env)
{
	char	*str;
	char	*pwd;
	char	*tmp;
	char	*usr;
	int		size;

	tmp = ft_strdup(ft_find_var(env, "PWD"));
	size = ft_strlen(ft_find_var(env, "HOME"));
	pwd = tmp;
	if (ft_strnstr(pwd, ft_find_var(env, "HOME"), size))
	{
		pwd += size - 1;
		pwd[0] = '~';
	}
	usr = ft_find_var(env, "USER");
	size = ft_strlen(pwd) + ft_strlen(usr) + 14;
	str = malloc((size + 1) * sizeof(char));
	if (!str || !tmp)
		return (NULL);
	if (!ft_strlcpy(str, usr, size) || !ft_strlcat(str, "@minishell:", size)
		|| !ft_strlcat(str, pwd, size) || !ft_strlcat(str, "$ ", size))
		return (NULL);
	str[size] = '\0';
	free(tmp);
	return (str);
}