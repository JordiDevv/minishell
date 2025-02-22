/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:25:01 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/22 17:48:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTORS_H
# define EXECUTORS_H

# define G "\033[32m"
# define R "\033[31m"
# define Y "\033[33m"
# define RE "\033[0m"

# define unlock 1
# define lock 0

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdbool.h>
# include "parser.h"

typedef struct  s_doors
{
    bool    input_door;
    bool    output_door;
}           t_doors;

typedef	struct	s_data
{
	char	**split_path;
	t_doors	*doors;
    int     **pipe_fds;
    char    *full_rute;
    int     pipe_index;
}	t_data;

void	ex_pwd(char **envp);
void	ex_echo(char *txt);
int     ex_exit(int n);

int     open_file(char *file, char redirection);
int     **prepare_pipes(t_list *lst);
int     redirect(int input, int output, int *fds);
int     execute_cmd(t_data *data, t_msh msh, char **split_cmd);

void    ex_loop(t_msh msh, t_data *data);
void    ex_built();
void    ex_native(t_data *program_data, t_msh msh, t_cmd *cmd);

void	get_path(t_data *data, t_msh *msh);
char	*strmcat(int n, int i, ...);

#endif