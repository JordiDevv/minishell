/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:24:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/15 12:42:09 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

void	ex_pwd(char **envp)
{
	char	*pwd_value;

	pwd_value = ft_find_var(envp, "PWD");
	if (!pwd_value)
	{
		printf(Y "Error: pwd is corrupted" RE);
		return ;
	}
	printf("%s\n", pwd_value);
}
