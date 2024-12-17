/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:32:22 by rhernand          #+#    #+#             */
/*   Updated: 2024/12/17 21:10:15 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command
{
	char		**envp;
	char		*cmd;
	char		**flags;
	char		*input;
	int			pipe;
	char		*output;
	t_command	*next;
}		t_command;

char		**ft_env_parser(char **envp);
char		*ft_find_var(char **envp, char *var);
char		*ft_expand_vars(char **envp, char *str);
char		*ft_subst_dolar(char **envp, char *str, int i, int j);
int			free_env(char **env);
t_command	*ft_proc_str(char *str, char **env);

#endif