/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:25:01 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 16:42:39 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

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
# include <limits.h>
# include <dirent.h>
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
    int     fd_input;
    int     fd_output;
    int     fd_stdin;
    int     fd_stdout;
    int     should_exit;
    char    **exported_vars;
}	t_data;

int     ex_pwd(void);
int     ex_echo(t_cmd *cmd);
void    ex_exit(t_data *data, t_cmd *cmd);
int     ex_env(char **envp, t_cmd *cmd);
int     ex_export(t_msh *msh, t_data *data, t_cmd *cmd);
int     ex_unset(t_msh *msh, t_data *data, t_cmd *cmd);
int     ex_cd(t_cmd *cmd, t_msh *msh, t_data *data);

void    show_export(t_data *data);
int     valid_var(char *var);
int     locate_var(char **mat, char *var);
void    modify_var(char **mat, char *var, int i);
void    add_var(char ***mat, char *var);

void    open_file(t_data *data, t_cmd *cmd);
int     **prepare_pipes(t_list *lst);
int     native_redirect(int input, int output, t_data *data);
void    file_redirection(t_data *data, t_cmd *cmd);
int     execute_cmd(t_data *data, t_msh *msh, char **split_cmd);
void    end_process(t_data *data);

void    ex_loop(t_msh *msh, t_data *data);
void    ex_built(t_cmd *cmd, t_data *data, t_msh *msh);
void    ex_native(t_data *program_data, t_msh *msh, t_cmd *cmd);

void	get_path(t_data *data, t_msh *msh);
char	*strmcat(int n, int i, ...);
int     wait_childs();
char    *ft_realloc(char *old_str, size_t size);
char    **mat_realloc(char **old_mat, size_t size, char *unset);
void    free_mat(char **mat);
int     mat_len(char **mat);
void    matlcpy(char **dst, char **src, size_t size);
int     strccmp(char *s1, char *s2, char c);
int     strrefccmp(char *ref, char *cmp, char c);

void	ft_free_all(t_data *data, t_msh *msh);
void	ft_free_ex(t_data *data);

#endif