/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/20 14:49:06 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

/*Receives str and pointer to cmd. Iterates over str 
looking for key chars outside "" or ''.
Calls functions located in fill_cmd.c to fill the cmd struct. 
Calls ft_ptend() to end pointers. */

void	ft_cmd_fill(char *str, t_cmd *cmd)
{
	int		i;
	int		m[2];

	m[0] = 0;
	m[1] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			m[0] = (m[0] + 1) % 2;
		if (str[i] == '\'')
			m[1] = (m[1] + 1) % 2;
		if (str[i] == '<' && !m[0] && !m[1] && cmd->input == NULL)
			i = ft_redir_in(&str, cmd, i);
		else if (str[i] == '>' && !m[0] && !m[1] && cmd->output == NULL)
			i = ft_redir_out(&str, cmd, i);
		else if (cmd->full == NULL && str[i] != ' ' && str[i] != '<' \
				&& str[i] != '>')
			i = ft_full(&str, cmd, i, m);
		i++;
	}
	ft_ptend(&str);
	cmd->split = ft_split_adv(cmd->full, ' ');
}

/*Funcion recieves first node and substring "str", 
if first node does not exist, finds input and fills first node.
Otherwise, creates a new node, calls ft_cmd_fill to fill node->content
Adds node to the end of the list with ft_lstadd_back()*/

t_list	*ft_new_node(char *str, t_list *first, t_msh *msh)
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

t_list	*ft_proc_str(char *str, t_msh *msh)
{
	int			j;
	t_list		*first;
	int			m[2];

	j = 0;
	m[0] = 0;
	m[1] = 0;
	first = NULL;
	while (str[j])
	{
		if (str[j] == '\"')
			m[0] = (m[0] + 1) % 2;
		if (str[j] == '\'')
			m[1] = (m[1] + 1) % 2;
		if (str[j] == '|' && !m[0] && !m[1])
		{
			str[j] = '\0';
			first = ft_new_node(str, first, msh);
			str += (j-- + 1);
		}
		j++;
	}
	if (str[0])
		first = ft_new_node(str, first, msh);
	return (first);
}
