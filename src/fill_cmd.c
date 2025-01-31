/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:09:44 by rhernand          #+#    #+#             */
/*   Updated: 2025/01/31 13:32:49 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

int	ft_markfind(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		if (str[i])
			i++;
		return (i);
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		if (str[i])
			i++;
		return (i);
	}
	return (0);
}

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
	cmd->input = (*str) + i + 1;
	while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '>')
	{
		i += ft_markfind(&((*str)[i]));
		i++;
	}
	if ((*str)[i] && (*str)[i] != '>')
		(*str)[i] = '<';
	if (cmd->input && cmd->input[0] == '<')
		cmd->del = &((cmd->input)[1]);
	return (i - 1);
}

/*Recieves pointer to str the position of ">" char within str and
pointer to cmd to fill. Sets cmd->output and iterates until it finds
space or < outside "" or '' marks. Returns new position in str.*/

int	ft_redir_out(char **str, t_cmd *cmd, int i)
{
	cmd->output = (*str) + i + 1;
	while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '<')
	{
		i += ft_markfind(&((*str)[i]));
		i++;
	}
	if ((*str)[i] && (*str)[i] != '<')
		(*str)[i] = '>';
	if (cmd->output && cmd->output[0] == '>')
		cmd->append = &((cmd->output)[1]);
	return (i - 1);
}
