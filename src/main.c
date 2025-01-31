/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/31 15:30:15 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
// #include "../inc/parser.h"

// void	ft_print_list(t_msh *msh)
// {
// 	t_list	*aux;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 1;
// 	aux = msh->lst;
// 	while (aux)
// 	{
// 		printf("\ncommand number %d\n", j);
// 		printf("cmd built =  %s\n", ((t_cmd *) aux->content)->built);
// 		printf("cmd full =  %s\n", ((t_cmd *) aux->content)->full);
// 		printf("cmd input =  %s\n", ((t_cmd *) aux->content)->input);
// 		printf("cmd del =  %s\n", ((t_cmd *) aux->content)->del);
// 		printf("cmd output =  %s\n", ((t_cmd *) aux->content)->output);
// 		printf("cmd append =  %s\n", ((t_cmd *) aux->content)->append);
// 		while (((t_cmd *)aux->content)->split \
// 			&& ((t_cmd *)aux->content)->split[i])
// 		{
// 			printf("split %d = %s\n", i, ((t_cmd *) aux->content)->split[i]);
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 		aux = aux->next;
// 	}
// }

// /*Just an ASCII artpiece to know we entered MINISHELL*/

// void	ft_draw(void)
// {
// 	const char	*ascii = \
// 	"         _nnnn_\n" \
// 	"        dGGGGMMb     ,\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n" \
// 	"       @p~qp~~qMb    |     MINISHELL     |\n" \
// 	"       M|@||@) M|    | jsanz-bo rhernand |\n" \
// 	"       @,----.JM| -'_;...................'\n" \
// 	"      JS^\\__/  qKL\n" \
// 	"     dZP        qKRb\n" \
// 	"    dZP          qKKb\n" \
// 	"   fZP            SMMb\n" \
// 	"   HZM            MMMM\n" \
// 	"   FqM            MMMM\n" \
// 	" __| \".        |\\dS\"qML\n" \
// 	" |    `.       | `' \\Zq\n" \
// 	"_)      \\.___.|     .'\n" \
// 	"\\____   )MMMMMM|   .'\n" \
// 	"     `-'       `--'\n";

// 	printf("%s\n", ascii);
// }

// /*ft_prompt recieves environment, finds PWD, HOME and USER,
// finds if the current dir contains HOME dir and creates
// a str that simulates bash prompt*/

// char	*ft_prompt(char **env)
// {
// 	char	*str;
// 	char	*pwd;
// 	char	*tmp;
// 	char	*usr;
// 	int		size;

// 	tmp = ft_strdup(ft_find_var(env, "PWD"));
// 	size = ft_strlen(ft_find_var(env, "HOME"));
// 	pwd = tmp;
// 	if (ft_strnstr(pwd, ft_find_var(env, "HOME"), size))
// 	{
// 		pwd += size - 1;
// 		pwd[0] = '~';
// 	}
// 	usr = ft_find_var(env, "USER");
// 	size = ft_strlen(pwd) + ft_strlen(usr) + 14;
// 	str = malloc((size + 1) * sizeof(char));
// 	if (!str || !tmp)
// 		return (NULL);
// 	if (!ft_strlcpy(str, usr, size) || !ft_strlcat(str, "@minishell:", size) \
// 		|| !ft_strlcat(str, pwd, size) || !ft_strlcat(str, "$ ", size))
// 		return (NULL);
// 	str[size] = '\0';
// 	free(tmp);
// 	return (str);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*input;
// 	char	*str;
// 	char	*prompt;
// 	t_msh	msh;

// 	ft_draw();
// 	msh.env = ft_env_parser(envp);
// 	while (1)
// 	{
// 		prompt = ft_prompt(msh.env);
// 		input = readline(prompt);
// 		printf("input = %s\n", input);
// 		str = ft_expand_vars(msh.env, input);
// 		printf("expanded str = %s\n", str);
// 		str = ft_expand_home(msh.env, str);
// 		printf("expanded home = %s\n", str);
// 		msh.lst = ft_proc_str(str, &msh);
// 		ft_print_list(&msh);
// 		free(str);
// 		if (input == NULL)
// 			break ;
// 	}
// 	ft_free_env(msh.env);
// 	return (0);
// }
