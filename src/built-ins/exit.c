/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/30 10:14:28 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

static long	ft_atol_safe(const char *str, bool *long_range)
{
	int		sign;
	int		i;
	long	n;

	sign = 1;
	n = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && (n > (LONG_MAX - (str[i] - 48)) / 10))
			*long_range = false;
		if (sign == -1 && (n > (-(LONG_MIN + (str[i] - 48)) / 10)))
			*long_range = false;
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

static bool	valid_number(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ex_exit(t_data *data, t_cmd *cmd)
{
	bool	is_number;
	long	n;
	bool	long_range;

	long_range = true;
	if (cmd->split[1])
	{
		is_number = valid_number(cmd->split[1]);
		if (is_number)
			n = ft_atol_safe(cmd->split[1], &long_range);
		if (is_number && cmd->split[2])
		{
			write(2, "bash: exit: too many arguments\n", 31);
			return ;
		}
		else if (!is_number || !long_range)
		{
			write(2, "exit: bash: numeric argument required\n", 38);
			g_exit_status = 2;
		}
		else if (is_number)
			g_exit_status = n;
	}
	g_exit_status = (unsigned char)g_exit_status;
	data->should_exit = 1;
}
