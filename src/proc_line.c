/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/23 18:47:54 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

/*Function finds input, creates input file, opens it, assigns
file descriptor to node->input and returns line without input*/

int	ft_full(char **str, t_cmd *cmd, int i, int *m)
{
	char	*aux;

	aux = (*str) + i;
	if (ft_strnstr(*str, "echo", 4) && cmd->built == NULL)
		cmd->built = ft_strdup("echo");
	while (aux[i] != '<' && aux[i] != '>' && aux[i])
		i++;
	if (aux[i])
		aux[i - 1] = '\0';
	cmd->full = ft_split(aux, ' ');
}

int	*ft_redir_in(char **str, t_cmd *cmd, int i)
{
	cmd->input = (*str) + i;
	while (*(str[i]) && *(str[i]) != ' ')
	{
		if (*(str[i]) == '\"')
		{
			*(str[i]) = ' ';
			while (*(str[i]) && *(str[i]) != '\"')
				i++;
			if (*(str[i]))
				*(str[i]) = ' ';
		}
		else if (*(str[i]) == '\'')
		{
			*(str[i]) = ' ';
			while (*(str[i]) && *(str[i]) != '\'')
				i++;
			if (*(str[i]))
				*(str[i]) = ' ';
		}
		i++;
	}
	*(str[i]) = '\0';
	return (i);
}

int	ft_redir_out(char **str, t_cmd *cmd, int i)
{
	cmd->output = (*str) + i;
	while (*(str[i]) && *(str[i]) != ' ')
	{
		if (*(str[i]) == '\"')
		{
			*(str[i]) = ' ';
			while (*(str[i]) && *(str[i]) != '\"')
				i++;
			if (*(str[i]))
				*(str[i]) = ' ';
		}
		else if (*(str[i]) == '\'')
		{
			*(str[i]) = ' ';
			while (*(str[i]) && *(str[i]) != '\'')
				i++;
			if (*(str[i]))
				*(str[i]) = ' ';
		}
		i++;
	}
	*(str[i] = '\0');
	return (i);
}

void	ft_cmd_fill(char *str, t_cmd *cmd)
{
	int		i;
	int		m[2];

	m[0] = 0;
	m[1] = 0;
	i = 0;
	while (str[i])
	{
		if (str[j] == '\"')
			m[0] = (m[0] + 1) % 2;
		if (str[j] == '\'')
			m[1] = (m[1] + 1) % 2;
		if (str[i] == '<' && !m[0] && !m[1] && cmd->input == NULL)
			i = ft_redir_in(&str, cmd, i);
		else if (str[i] == '>' && !m[0] && !m[1] && cmd->output == NULL)
			i = ft_redir_out(&str, cmd, i);
		else if (cmd->full == NULL)
			i = ft_full(&str, cmd, i, m);
		i++;
	}
}

/*Funcion recieves first node and substring "str", 
if first node does not exist, finds input and fills first node.
Otherwise, creates a new node, fills it and adds it to the end of the list*/

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
	cmd->input = 0;
	cmd->output = 1;
	cmd->abs = NULL;
	cmd->full = NULL;
	ft_cmd_fill(str, node);
	node->content = (void *) cmd;
	node->next = NULL;
	ft_lstadd_back(&first, node);
	return (first);
}

/*function finds pipes "|" in str, chops them,
creates first node and sends the chopped strs to function to fill
and place the rest of the nodes within the linked list*/

t_list	ft_proc_str(char *str, t_msh *msh)
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
	return (*first);
}
