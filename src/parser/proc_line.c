/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2025/05/09 15:28:14 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	ft_strctrim(char **str, int sgl, int dbl)
{
	int		i;
	int		j;
	int		mark_dbl;
	int		mark_sgl;

	i = 0;
	mark_dbl = 0;
	mark_sgl = 0;
	while (str[0][i])
	{
		j = i;
		if (str[0][i] == '\'' && sgl % 2 == 0 && mark_dbl % 2 == 0)
		{
			mark_sgl++;
			while (str[0][j++])
				str[0][j - 1] = str[0][j];
		}
		else if (str[0][i] == '\"' && dbl % 2 == 0 && mark_sgl % 2 == 0)
		{
			mark_dbl++;
			while (str[0][j++])
				str[0][j - 1] = str[0][j];
		}
		else
			i++;
	}
}

void	ft_trim(char **split)
{
	int	i;
	int	j;
	int	sgl;
	int	dbl;

	i = 0;
	j = 0;
	if (!split || !*split)
		return ;
	while (split[i])
	{
		j = 0;
		sgl = 0;
		dbl = 0;
		while (split[i][j])
		{
			if (split[i][j] == '\'')
				sgl++;
			if (split[i][j] == '\"')
				dbl++;
			j++;
		}
		ft_strctrim(&split[i], sgl, dbl);
		i++;
	}
}

/*Receives str and pointer to cmd. Iterates over str 
looking for key chars outside "" or ''.
Calls functions located in fill_cmd.c to fill the cmd struct. 
Calls ft_ptend() to end pointers. */

void	ft_cmd_fill(char *str, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (cmd->full == NULL && str[i] != ' ' && str[i] != '<'
			&& str[i] != '>')
			i = ft_full(&str, cmd, i);
		i += ft_markfind(str + i);
		if (str[i] == '<' && cmd->input == NULL)
			i = ft_redir_in(&str, cmd, i);
		else if (str[i] == '>' && cmd->output == NULL)
			i = ft_redir_out(&str, cmd, i);
		i++;
	}
	ft_ptend(&str);
	cmd->split = ft_split_adv(cmd->full, ' ');
	ft_trim(cmd->split);
	ft_trim(&cmd->append);
	ft_trim(&cmd->del);
	ft_trim(&cmd->input);
	ft_trim(&cmd->output);
}

/*Funcion recieves first node and substring "str", 
if first node does not exist, finds input and fills first node.
Otherwise, creates a new node, calls ft_cmd_fill to fill node->content
Adds node to the end of the list with ft_lstadd_back()*/

t_list	*ft_new_node(char *str, t_list *first)
{
	t_cmd	*cmd;
	t_list	*node;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->built = NULL;
	cmd->full = NULL;
	cmd->split = NULL;
	cmd->del = NULL;
	cmd->append = NULL;
	ft_cmd_fill(str, cmd);
	node->content = (void *) cmd;
	node->next = NULL;
	ft_lstadd_back(&first, node);
	return (first);
}

/*function finds pipes "|" in str, chops them,
creates first node and sends the chopped strs to function to fill
and place the rest of the nodes within the linked list*/

t_list	*ft_proc_str(char *str)
{
	int			j;
	t_list		*first;
	char		*aux;

	j = 0;
	first = NULL;
	aux = str;
	while (aux[j])
	{
		j += ft_markfind(aux + j);
		if (aux[j] == '|')
		{
			aux[j] = '\0';
			first = ft_new_node(aux, first);
			aux += (j + 1);
			j = -1;
		}
		j++;
	}
	if (aux[0])
		first = ft_new_node(aux, first);
	return (first);
}
