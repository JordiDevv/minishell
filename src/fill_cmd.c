/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:09:44 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/23 14:17:37 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

/*After pointers are set up, ft_ptend() finds key chars
outside "" or '' marks. Overrides them with "\0" 
to set an end to the elements of cmd*/

void	ft_ptend(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		i += ft_markfind(&((*str)[i]));
		if ((*str)[i] == '<' || (*str)[i] == '>')
			(*str)[i] = '\0';
		i++;
	}
}
/*Receives pointer to str, start position of cmd-full, pointer to 
cmd and switches to tell if it is inside or outside "" or '' signs.
sets cmd->full pointer. if cmd is builtin, sets cmd->builtin.
iterates untill if finds key char*/

int	ft_full(char **str, t_cmd *cmd, int i, int *m)
{
	cmd->full = (*str) + i;
	if (ft_strnstr((*str) + i, "echo", 4) && cmd->built == NULL)
		cmd->built = ft_strdup("echo");
	if (ft_strnstr((*str) + i, "pwd", 3) && cmd->built == NULL)
		cmd->built = ft_strdup("pwd");
	if (ft_strnstr((*str) + i, "cd", 2) && cmd->built == NULL)
		cmd->built = ft_strdup("cd");
	if (ft_strnstr((*str) + i, "export", 6) && cmd->built == NULL)
		cmd->built = ft_strdup("export");
	if (ft_strnstr((*str) + i, "unset", 5) && cmd->built == NULL)
		cmd->built = ft_strdup("unset");
	if (ft_strnstr((*str) + i, "env", 3) && cmd->built == NULL)
		cmd->built = ft_strdup("env");
	if (ft_strnstr((*str) + i, "exit", 4) && cmd->built == NULL)
		cmd->built = ft_strdup("exit");
	while ((*str)[i] != '<' && (*str)[i] != '>' && (*str)[i])
	{
		i += ft_markfind(&((*str)[i]));
		i++;
	}
	return (i - 1);
}
/*Recieves pointer to str the position of "<" char within str and
pointer to cmd to fill. Sets cmd->input and iterates until it finds
space or > outside "" or '' marks. Returns new position in str.*/

int	ft_redir_in(char **str, t_cmd *cmd, int i)
{
	i++;
	if ((*str)[i] && (*str)[i] == '<')
	{
		i++;
		while ((*str)[i] && (*str)[i] == ' ')
			i++;
		cmd->del = (*str) + i;
	}
	else
	{
		while ((*str)[i] && (*str)[i] == ' ')
			i++;
		cmd->input = (*str) + i;
	}
	while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '>')
	{
		i += ft_markfind(&((*str)[i]));
		i++;
	}
	if ((*str)[i] && (*str)[i] != '>')
		(*str)[i] = '<';
	if (!(*str)[i])
		return (i - 1);
	return (i);
}

/*Recieves pointer to str the position of ">" char within str and
pointer to cmd to fill. Sets cmd->output and iterates until it finds
space or < outside "" or '' marks. Returns new position in str.*/

int	ft_redir_out(char **str, t_cmd *cmd, int i)
{
	i++;
	if ((*str)[i] && (*str)[i] == '>')
	{
		i++;
		while ((*str)[i] && (*str)[i] == ' ')
			i++;
		cmd->append = (*str) + i;
	}
	else
	{
		while ((*str)[i] && (*str)[i] == ' ')
			i++;
		cmd->output = (*str) + i;
	}
	while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '<')
	{
		i += ft_markfind(&((*str)[i]));
		i++;
	}
	if ((*str)[i] && (*str)[i] != '<')
		(*str)[i] = '>';
	if (!(*str)[i])
		return (i - 1);
	return (i);
}
