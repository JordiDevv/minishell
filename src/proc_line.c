/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:48 by rhernand          #+#    #+#             */
/*   Updated: 2024/12/17 22:38:58 by rhernand         ###   ########.fr       */
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

char	*ft_input(char **str)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	if (*(str[0]) == '<')
	{
		if (*(str[1]) == '<')
		{
			tmp = ft_strdup("delimiter");
			*str = ft_strchr(*str, ' ');
		}
		else
		{
			while (*(str[i]) != ' ')
				i++;
			tmp = ft_substr(str, 2, (i - 2));
			*str += i;
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
		new->input = ft_input(&str);
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
	int			i;
	int			j;
	char		*line;
	t_command	node;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '|')
		{
			line = ft_substr(str, i, (j - i + 1));
			ft_new_node(line, &node, env);
			free(line);
			i = j + 1;
		}
		j++;
	}
	if (i < j)
	{
		line = ft_substr(str, i, (j - i + 1));
		ft_new_node(line, &node, env);
		free(line);
	}
	return (&node);
}
