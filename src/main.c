/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/12 12:50:17 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/inc/libft.h"
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
	if (!ft_strlcpy(str, usr, size) || !ft_strlcat(str, "@minishell:", size) \
		|| !ft_strlcat(str, pwd, size) || !ft_strlcat(str, "$ ", size))
		return (NULL);
	str[size] = '\0';
	free(tmp);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*str;
	char	**env;
	char	*prompt;

	env = ft_env_parser(envp);
	while (1)
	{
		prompt = ft_prompt(env);
		input = readline(prompt);
		printf("input = %s\n", input);
		str = ft_expand_vars(env, input);
		printf("expanded str = %s\n", str);
		str = ft_expand_home(env, str);
		printf("expanded home = %s\n", str);
		//ft_proc_str(str, envp);
		free(str);
		if (input == NULL)
			break ;
	}
	ft_free_env(env);
	return (0);
}
