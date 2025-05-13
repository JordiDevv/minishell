/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:57 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/13 16:11:01 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"
#include "../inc/executor.h"

static void	init_minishell(t_data *data, t_msh *msh, char **envp)
{
	size_t	env_size;
	int		i;

	msh->env = ft_env_parser(envp);
	i = locate_var(msh->env, "OLDPWD");
	if (i < 0)
		add_var(&(msh->env), "OLDPWD");
	else
		modify_var(msh->env, "OLDPWD", i);
	env_size = (mat_len(msh->env) + 1) * sizeof(char *);
	data->exported_vars = malloc(env_size);
	if (!data->exported_vars)
		return ;
	matlcpy(data->exported_vars, msh->env, env_size);
	data->doors = malloc(sizeof(t_doors));
	if (!data->doors)
	{
		free (data->exported_vars);
		return ;
	}
}

static void	ft_init_data(t_data *data, t_msh *msh)
{
	data->split_path = NULL;
	get_path(data, msh);
	data->full_rute = NULL;
	data->pipe_fds = NULL;
	data->pids = NULL;
	data->hd_flag = 0;
    data->abs_flag = 0;
	data->pipe_index = 0;
	data->fd_input = 0;
	data->fd_output = 0;
	data->fd_stdin = 0;
	data->fd_stdout = 0;
	data->should_exit = 0;
	data->doors->input_door = LOCK;
	data->doors->output_door = LOCK;
	msh->prompt = ft_prompt(msh->env);
}

static int	init_dynamic_data(t_msh *msh, t_data *data)
{
	ft_init_data(data, msh);
	if (isatty(STDIN_FILENO))
	{
		ft_prompt_marks(msh);
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
	if (ft_dbl_pipe(msh->input))
		return (3);
	msh->str = ft_expand_vars(msh->env, msh->input);
	msh->str = ft_expand_home(msh->env, msh->str);
	msh->lst = ft_proc_str(msh->str);
	data->pids = prepare_pids(msh->lst);
	data->pipe_fds = prepare_pipes(msh->lst);
	return (0);
}

static void	main_loop(t_msh *msh, t_data *data)
{
	msh->parse_flag = init_dynamic_data(msh, data);
	if (!msh->parse_flag)
	{
		ex_loop(msh, data);
		wait_children(data);
		free(msh->str);
		ft_free_ex(data);
		ft_free_nodes(msh->lst);
	}
	if (*msh->prompt)
		free(msh->prompt);
	if (data->split_path)
		free_mat(data->split_path);
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_data	data;

	argc++;
	if (!argv[0])
		return (0);
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
