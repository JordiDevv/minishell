/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/29 12:10:39 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"
#include "../inc/executor.h"

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

static void	ft_init_data(t_data *data)
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

static void	main_loop(t_msh *msh, t_data *data)
{
	msh->parse_flag = init_dynamic_data(msh, data);
	if (!msh->parse_flag)
	{
		ex_loop(msh, data);
		free(msh->str);
		ft_free_ex(data, msh);
		ft_free_nodes(msh->lst);
	}
	free(msh->prompt);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*aux_lst;
	t_msh	msh;
	t_data	data;

	if (!envp[0])
	{
		write(2, "Error: no environment received\n", 31);
		return (1);
	}
	init_minishell(&data, &msh, envp);
	ft_signal();
	while (1)
	{
		main_loop(&msh, &data);
		if (data.should_exit || msh.parse_flag == 1)
			break ;
	}
	ft_free_all(&data, &msh);
	write(1, "exit\n", 5);
	return (g_exit_status);
}

//Reservamos memoria para data->doors
//En "create_pipes" reservamos memoria para pipes_fds