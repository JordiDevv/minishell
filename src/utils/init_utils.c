/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:05:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/27 18:06:32 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void	ft_print_list(t_msh *msh)
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
	if (!ft_strlcpy(str, usr, size) || !ft_strlcat(str, "@minishell:", size)
		|| !ft_strlcat(str, pwd, size) || !ft_strlcat(str, "$ ", size))
		return (NULL);
	str[size] = '\0';
	free(tmp);
	return (str);
}
