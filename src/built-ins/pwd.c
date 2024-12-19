/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:24:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/12/19 13:12:15 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

void	ex_pwd(char **envp)
{
	char	pwd_value;

	pwd_value = ft_find_var(envp, "PWD");
	if (!pwd_value)
	{
		printf(Y "Error: pwd is corrupted" RE);
		return ;
	}
	printf("%s", pwd_value);
}
