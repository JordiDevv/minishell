/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:35:14 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/12 11:37:55 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/inc/libft.h"
#include "../inc/parser.h"

/*Receives str with marker pointing to ~ sign (i). 
Finds home in envp and returns new string copying home in the right place*/
char	*ft_subst_home(char **envp, char *str, int i)
{
	char	*home;
	char	*tmp;
	int		length;

	home = ft_find_var(envp, "HOME");
	if (!home)
		return (str);
	length = ft_strlen(str) + ft_strlen(home);
	tmp = malloc (length * sizeof(char));
	if (!tmp)
		return (NULL);
	if (!ft_strlcpy(tmp, str, i + 1) || !ft_strlcat(tmp, home, length) \
			|| !ft_strlcat(tmp, (str + (i + 1)), length))
		return (NULL);
	tmp[length] = '\0';
	return (tmp);
}

/*Identifies ~ signs in str, expands with home dir.
returns string with home dir expanded. */
char	*ft_expand_home(char **envp, char *str)
{
	int		i;
	int		m[2];

	i = 0;
	m[0] = 0;
	m[1] = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			m[0] = (m[0] + 1) % 2;
		if (str[i] == '\'')
			m[1] = (m[1] + 1) % 2;
		if (str[i] == '~' && !m[0] && !m[1])
			str = ft_subst_home(envp, str, i);
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
