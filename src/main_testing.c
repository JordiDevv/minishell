/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/02/22 12:49:05 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"
#include "../inc/executor.h"

static void	ft_print_list(t_msh *msh)
{
	t_list	*aux;
	int		i;
	int		j;

	i = 0;
	j = 1;
	aux = msh->lst;
	while (aux)
	{
		printf("\ncommand number %d\n", j);
		printf("cmd built =  %s\n", ((t_cmd *) aux->content)->built);
		printf("cmd full =  %s\n", ((t_cmd *) aux->content)->full);
		printf("cmd input =  %s\n", ((t_cmd *) aux->content)->input);
		printf("cmd del =  %s\n", ((t_cmd *) aux->content)->del);
		printf("cmd output =  %s\n", ((t_cmd *) aux->content)->output);
		printf("cmd append =  %s\n", ((t_cmd *) aux->content)->append);
		while (((t_cmd *)aux->content)->split \
			&& ((t_cmd *)aux->content)->split[i])
		{
			printf("split %d = %s\n", i, ((t_cmd *) aux->content)->split[i]);
			i++;
		}
		i = 0;
		j++;
		aux = aux->next;
	}
}

/*Just an ASCII artpiece to know we entered MINISHELL*/

void	ft_draw(void)
{
	const char	*ascii = \
	"         _nnnn_\n" \
	"        dGGGGMMb     ,\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n" \
	"       @p~qp~~qMb    |     MINISHELL     |\n" \
	"       M|@||@) M|    | jsanz-bo rhernand |\n" \
	"       @,----.JM| -'_;...................'\n" \
	"      JS^\\__/  qKL\n" \
	"     dZP        qKRb\n" \
	"    dZP          qKKb\n" \
	"   fZP            SMMb\n" \
	"   HZM            MMMM\n" \
	"   FqM            MMMM\n" \
	" __| \".        |\\dS\"qML\n" \
	" |    `.       | `' \\Zq\n" \
	"_)      \\.___.|     .'\n" \
	"\\____   )MMMMMM|   .'\n" \
	"     `-'       `--'\n";

	printf("%s\n", ascii);
}

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

static void	init_minishell(t_data *data, t_msh *msh, char **envp)
{
	ft_draw();
	msh->env = ft_env_parser(envp);
	get_path(data, msh);
	data->doors = malloc(sizeof(t_doors));
}

static void	init_dynamic_data(t_msh *msh, t_data *data)
{
	msh->prompt = ft_prompt(msh->env);
	msh->input = readline(msh->prompt);
	msh->str = ft_expand_vars(msh->env, msh->input);
	msh->str = ft_expand_home(msh->env, msh->str);
	msh->lst = ft_proc_str(msh->str, msh);
	data->pipe_fds = prepare_pipes(msh->lst);
	data->pipe_index = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*aux_lst;
	t_msh	msh;
	t_data	data;

	init_minishell(&data, &msh, envp);
	while (1)
	{
		init_dynamic_data(&msh, &data);
		ft_print_list(&msh);
		data.doors->input_door = 0;
		data.doors->output_door = 0;
		ex_loop(msh, &data);
		free(msh.str);
		if (msh.input == NULL)
			break ;
	}
	ft_free_env(msh.env);
	return (0);
}


//Hay que revisar la matriz de pipes del pipex y cómo lo podemos adaptar a la minishell, o
//explorar otras alternativas.

//Reservamos memoria para data->doors
//En "create_pipes" reservamos memoria para pipes_fds