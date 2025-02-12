/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/02/12 12:11:42 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"
#include "../inc/executor.h"

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

static void	init_minishell(t_data **data, char **envp)
{
	t_msh	*msh;
	
	ft_draw();
	msh->env = ft_env_parser(envp);
	(*data) = malloc(sizeof(t_data));
	(*data)->msh = msh;
	get_path(*data);
	(*data)->doors = malloc(sizeof(t_doors));
}

static void	init_dynamic_data(t_data **data)
{
	(*data)->msh->prompt = ft_prompt((*data)->msh->env);
	(*data)->msh->input = readline((*data)->msh->prompt);
	(*data)->msh->str = ft_expand_vars((*data)->msh->env, (*data)->msh->input);
	(*data)->msh->str = ft_expand_home((*data)->msh->env, (*data)->msh->str);
	(*data)->msh->lst = ft_proc_str((*data)->msh->str, (*data)->msh);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	t_list	*aux_lst;
	t_data	*data;
	int		n_cmd;

	init_minishell(&data, envp);
	n_cmd = 1;
	while (1)
	{
		init_dynamic_data(&data);
		data->doors->input_door = 0;
		data->doors->output_door = 0;
		aux_lst = data->msh->lst;
		while (aux_lst)
		{
			if (aux_lst->next)
				data->doors->output_door = 1;
			else
				data->doors->output_door = 0;
			cmd = ((t_cmd *) aux_lst->content);
			if (cmd->built)
				ex_built();
			else
				ex_native(data, cmd, n_cmd);
			if (!data->doors->input_door)
				data->doors->input_door = 1;
			aux_lst = aux_lst->next;
		}
		free(data->msh->str);
		if (data->msh->input == NULL)
			break ;
	}
	ft_free_env(data->msh->env);
	return (0);
}


//Hay que revisar la matriz de pipes del pipex y cómo lo podemos adaptar a la minishell, o
//explorar otras alternativas.

//Reservamos memoria para data y para data->doors
//En "create_pipes" reservamos memoria para pipes_fds