/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:24:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 11:55:39 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

int	ex_pwd(char **envp)
{
	char	*pwd_value;

	pwd_value = getcwd(NULL, 0);
	if (!pwd_value)
	{
		write(2, "Error: pwd is corrupted\n", 24);
		return (1);
	}
	write(1, pwd_value, ft_strlen(pwd_value));
	write(1, "\n", 1);
	free(pwd_value);
	return (0);
}
