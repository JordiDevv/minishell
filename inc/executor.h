/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:25:01 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/02/10 12:49:49 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTORS_H
# define EXECUTORS_H

# define G "\033[32m"
# define R "\033[31m"
# define Y "\033[33m"
# define RE "\033[0m"

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

void	ex_pwd(char **envp);
void	ex_echo(char *txt);
int     ex_exit(int n);

int     open_file(char *file, char redirection);
int     *create_pipe();
int     redirect(int input, int output, int *fds);
int     execute_cmd(int *pipe_fds, char *rute, char **split_cmd, t_data *data);

void    ex_built();
void    ex_native(t_data *program_data, t_cmd *cmd, int n_cmd);

void	get_path(t_data *msh);
char	*strmcat(int n, int i, ...);

#endif