/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:20:47 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/24 20:57:37 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	get_path(t_data *program_data, int i)
{
	char	*path;

	path = NULL;
	while (program_data->environ[++i])
	{
		if (!ft_strncmp(program_data->environ[i], "PATH=", 5))
		{
			path = malloc(ft_strlen(program_data->environ[i]) - 4);
			if (!path)
			{
				perror(R "Error allocating path\n" RE);
				free_exit(program_data);
			}
			ft_strlcpy(path, program_data->environ[i] + 5,
				ft_strlen(program_data->environ[i]) - 4);
		}
	}
	if (!path)
	{
		ft_printf(R "Error: Path wasn't found\n" RE);
		free_exit(program_data);
	}
	program_data->path_mat = ft_split(path, ':');
	free(path);
}

static void	create_pipes(t_data *program_data, int n, int i)
{
	program_data->pipe = malloc(sizeof(int *) * (n + 1));
	if (!program_data->pipe)
	{
		perror(R "Error allocating the pipe\n" RE);
		free_exit(program_data);
	}
	program_data->pipe[n] = NULL;
	while (i--)
	{
		program_data->pipe[i] = malloc(sizeof(int) * 2);
		if (!program_data->pipe[i])
		{
			perror(R "Error allocating the pipe\n" RE);
			free_exit(program_data);
		}
	}
	while (++i < n)
	{
		if (pipe(program_data->pipe[i]) < 0)
		{
			perror(R "Error creating the pipe\n" RE);
			free_exit(program_data);
		}
	}
}

static void	open_files(char **args, t_data *program_data)
{
	if (access(args[1], F_OK))
		ft_printf(Y "-bash: %s: %s\n" RE, args[1], strerror(errno));
	else
	{
		program_data->fds[0] = open(args[1], O_RDONLY);
		if (program_data->fds[0] < 0)
		{
			perror(R "Error opening the first file despite was found\n" RE);
			exit (EXIT_FAILURE);
		}
		program_data->file1 = 1;
	}
	program_data->fds[1] = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR);
	if (program_data->fds[1] < 0)
	{
		perror(R "Error opening or creating the second file\n" RE);
		free_exit(program_data);
		exit (EXIT_FAILURE);
	}
}

static void	ex_flow(t_data *program_data, char **argv)
{
	program_data->step = 1;
	if (program_data->file1)
		valid_cmd(argv[2], program_data);
	if (program_data->cmd1)
		ex_cmd1(program_data, 0);
	close(program_data->pipe[0][1]);
	program_data->step = 2;
	valid_cmd(argv[3], program_data);
	if (program_data->cmd2)
		ex_cmd2(program_data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	program_data;

	if (argc != 5)
	{
		ft_printf(R "The program expects \e[3mexactly\e[23m 4 arguments\n" RE);
		return (0);
	}
	ft_bzero(&program_data, sizeof(t_data));
	program_data.environ = env;
	open_files(argv, &program_data);
	create_pipes(&program_data, argc - 4, argc - 4);
	get_path(&program_data, -1);
	if (!program_data.path_mat)
	{
		ft_printf(R "Error spliting the path\n" RE);
		free_exit(&program_data);
	}
	ex_flow(&program_data, argv);
	wait(NULL);
	free_exit(&program_data);
	return (0);
}
