/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/10 21:35:07 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

int	ft_add_content(char *str, t_command *new, char **env)
{
	int	i;
	
	i = 0;
	new->envp = env;
	new->next = NULL;
	if (str[0] == '|')
		return (1);
	if (ft_strchr(str, '|'))
		new->pipe = 1;
	else
		new->pipe = 0;
	return (0);
}

char	*ft_input(t_command *new, char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	if (str[i] == '<')
	{
		while (str[i])
		{
			if (str[i] == '"')
			{
				while (str[i] != '"')
					i++;
				str += i + 1;
			}
		}
	}
	return (tmp);
}

/*Funcion recieves first node and substring "str", 
if first node does not exist, finds input and fills first node.
Otherwise, creates a new node, fills it and adds it to the end of the list*/
void	ft_new_node(char *str, t_command *first, char **env)
{
	t_command	*new;

	if (!first->cmd)
	{
		new = first;
		if (str[0] == '|')
			return (perror("PIPE in wrong place"));
		str = ft_input(new, str);
	}
	else
	{
		new = malloc(sizeof(t_command));
		if (!new)
			return (perror("malloc error"));
		new->input = NULL;
	}
	if (ft_add_content(str, new, env) == 0)
		ft_lstadd_back(&first, new);
	else if (first->cmd)
		free (new);
	return ;
}

/*function finds pipes "|" in str, chops them,
creates first node and sends the chopped strs to functions to fill
and place the rest of the nodes within the linked list*/
t_command	*ft_proc_str(char *str, char **env)
{
	int			j;
	char		*line;
	t_command	node;

	j = 0;
	while (str[j])
	{
		if (str[j] == '|')
		{
			line = str;
			line[j - 1] = '\0';
			str += (j + 1);
			ft_new_node(line, &node, env);
			free(line);
			j = -1;
		}
		j++;
	}
	if (str[0])
		ft_new_node(str, &node, env);
	return (&node);
}
