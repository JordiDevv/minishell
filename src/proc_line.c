/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/20 12:11:45 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

/*Function finds input, creates input file, opens it, assigns
file descriptor to node->input and returns line without input*/

char	*ft_redir_in(char *str, int i, t_cmd *new)
{
	char	*tmp;
	char	*line;
	char	*next;
	int		size;
	int		j;

	j = 0;
	if (str[i + 1] != '<')
	{
		tmp = str + i;
		while (str[i] && str[i] != ' ')
			j++;
		tmp[j] = '\0';
		next = tmp + j + 1;
		new->input = open(tmp, O_RDONLY);
		if (new->input == -1)
			return (NULL);
	}
	size = ft_strlen(str) - ft_strlen(tmp) + ft_strlen(next);
	line = malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	if (!ft_strlcpy(line, str, size) || !ft_strlcpy(line, next, size))
		return (NULL);
	return (line);
}

char	*ft_redir(char *str, t_cmd *new)
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
		if (str[i] == '<' && !m[0] && !m[1])
		{
			str = ft_redir_in(str, i, new);
			i = -1;
		}
		else if (str[i] == '>' && !m[0] && !m[1])
		{
			str = ft_redir_out(str, i, new);
			i = -1;
		}
		i++;
	}
	return (str);
}

/*Funcion recieves first node and substring "str", 
if first node does not exist, finds input and fills first node.
Otherwise, creates a new node, fills it and adds it to the end of the list*/

void	ft_new_node(char *str, t_cmd *first, t_msh *msh)
{
	t_cmd	new;
	int		m[2];

	m[0] = 0;
	m[1] = 0;
	new.input = 0;
	new.output = 1;
	new.cmd = NULL;
	if (ft_strchr(str, '<') || ft_strchr(str, '>'))
		str = ft_redir(str, &new);
	new.cmd = "/bin/wc";
	new.flags = ft_split(str, ' ');
	ft_lstadd_back((void *)&(*first), (void *)&new);
	return ;
}

/*function finds pipes "|" in str, chops them,
creates first node and sends the chopped strs to function to fill
and place the rest of the nodes within the linked list*/

t_cmd	ft_proc_str(char *str, t_msh *msh)
{
	int			j;
	t_cmd		node;
	int			m[2];

	j = 0;
	m[0] = 0;
	m[1] = 0;
	while (str[j])
	{
		if (str[j] == '\"')
			m[0] = (m[0] + 1) % 2;
		if (str[j] == '\'')
			m[1] = (m[1] + 1) % 2;
		if (str[j] == '|' && !m[0] && !m[1])
		{
			str[j] = '\0';
			ft_new_node(str, &node, msh);
			str += (j + 1);
			j = -1;
		}
		j++;
	}
	if (str[0])
		ft_new_node(str, &node, msh);
	return (node);
}
