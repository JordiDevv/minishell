/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:32:22 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/29 23:44:50 by rhernand         ###   ########.fr       */
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
	char		*built;
	char		*full;
	char		**split;
	char		*input;
	char		*output;
}		t_cmd;

typedef struct s_msh
{
	char	**env;
	t_list	*lst;
}		t_msh;

char		**ft_env_parser(char **envp);
char		*ft_find_var(char **envp, char *var);
char		*ft_expand_vars(char **envp, char *str);
char		*ft_subst_dolar(char **envp, char *str, int i, int j);
int			ft_free_env(char **env);
t_list		*ft_proc_str(char *str, t_msh *msh);
char		*ft_expand_home(char **env, char *str);
char		*ft_subst_home(char **envp, char *str, int i);
char		*ft_prompt(char **env);
void		ft_draw(void);


#endif