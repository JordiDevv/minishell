/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:32:22 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/11 11:15:38 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	char		**envp;
	char		*cmd;
	char		**flags;
	char		*input;
	int			pipe;
	char		*output;
	void		*next;
}		t_cmd;

char		**ft_env_parser(char **envp);
char		*ft_find_var(char **envp, char *var);
char		*ft_expand_vars(char **envp, char *str);
char		*ft_subst_dolar(char **envp, char *str, int i, int j);
int			ft_free_env(char **env);
t_cmd		ft_proc_str(char *str, char **env);

#endif