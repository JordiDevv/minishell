/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/28 18:49:22 by rhernand         ###   ########.fr       */
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

void	ft_init_data(t_data *data)
{
	data->full_rute = NULL;
	data->pipe_fds = NULL;
	data->pipe_index = 0;
	data->fd_input = 0;
	data->fd_output = 0;
	data->fd_stdin = 0;
	data->fd_stdout = 0;
	data->should_exit = 0;
	data->doors->input_door = lock;
	data->doors->output_door = lock;
}

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

static void	init_minishell(t_data *data, t_msh *msh, char **envp)
{
	size_t	env_size;

	ft_draw();
	msh->env = ft_env_parser(envp);
	env_size = (mat_len(msh->env) + 1) * sizeof(char *);
	data->exported_vars = malloc(env_size);
	matlcpy(data->exported_vars, msh->env, env_size);
	get_path(data, msh);
	data->doors = malloc(sizeof(t_doors));
}

static int	init_dynamic_data(t_msh *msh, t_data *data)
{
	msh->prompt = ft_prompt(msh->env);
	ft_init_data(data);
	if (isatty(STDIN_FILENO))
	{
		msh->input = readline(msh->prompt);
		if (!msh->input)
			return (1);
		if (*(msh->input) == '\0')
			return (2);
	}
	else
	{
		msh->input = ft_get_next_line(STDIN_FILENO);
		write (1, "\n", 1);
		if (!msh->input)
			return (1);
	}
	add_history(msh->input);
	msh->str = ft_expand_vars(msh->env, msh->input);
	msh->str = ft_expand_home(msh->env, msh->str);
	msh->lst = ft_proc_str(msh->str, msh);
	data->pipe_fds = prepare_pipes(msh->lst);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*aux_lst;
	t_msh	msh;
	t_data	data;

	init_minishell(&data, &msh, envp);
	ft_signal();
	while (1)
	{
		msh.parse_flag = init_dynamic_data(&msh, &data);
		if (!msh.parse_flag)
		{
			ex_loop(&msh, &data);
			free(msh.str);
			ft_free_ex(&data, &msh);
			ft_free_nodes(msh.lst);
		}
		if (msh.prompt && *msh.prompt)
			free(msh.prompt);
		if (data.should_exit || msh.parse_flag == 1)
			break ;
	}
	ft_free_all(&data, &msh);
	write(1, "exit\n", 5);
	return (g_exit_status);
}

//Reservamos memoria para data->doors
//En "create_pipes" reservamos memoria para pipes_fds