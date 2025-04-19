/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:24:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/19 11:51:54 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

int	ex_pwd(char **envp)
{
	char	*pwd_value;

	pwd_value = ft_find_var(envp, "PWD");
	if (!pwd_value)
	{
		printf(Y "Error: pwd is corrupted\n" RE);
		return (1);
	}
	printf("%s\n", pwd_value);
	return (0);
}
