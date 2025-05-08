/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:32:22 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/08 20:15:18 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdbool.h>
# include <signal.h>

extern volatile sig_atomic_t	g_exit_status;

typedef struct s_cmd
{
	char		*built;
	char		*full;
	char		**split;
	char		*input;
	char		*del;
	char		*output;
	char		*append;
}		t_cmd;

typedef struct s_msh
{
	char	**env;
	char	*input;
	char	*str;
	char	*prompt;
	t_list	*lst;
	int		parse_flag;
}		t_msh;

char		**ft_env_parser(char **envp);
char		*ft_find_var(char **envp, char *var);
char		*ft_expand_vars(char **envp, char *str);
char		*ft_subst_dolar(char **envp, char *str, int i, int j);
int			ft_free_env(char **env);
t_list		*ft_proc_str(char *str);
char		*ft_expand_home(char **env, char *str);
char		*ft_subst_home(char **envp, char *str, int i);
char		*ft_prompt(char **env);
void		ft_print_list(t_msh *msh);
void		ft_cmd_fill(char *str, t_cmd *cmd);
t_list		*ft_new_node(char *str, t_list *first);
void		ft_ptend(char **str);
int			ft_full(char **str, t_cmd *cmd, int i);
int			ft_redir_in(char **str, t_cmd *cmd, int i);
int			ft_redir_out(char **str, t_cmd *cmd, int i);
int			ft_markfind(char *str);
char		**ft_split_adv(const char *s, const char c);
void		ft_signal(void);
void		ft_free_nodes(t_list *lst);
int			ft_markfind_single(char *str);
void		ft_prompt_marks(t_msh *msh);
char		*ft_prompt(char **env);
void		sigint_handler(int signo);
void		ft_signal_flags(void);

#endif