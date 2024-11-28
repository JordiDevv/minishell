/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:24:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/29 00:24:56 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void	ex_pwd(char *pwd_value)
{
	if (!pwd_value)
	{
		printf(Y "Error: pwd is corrupted" RE);
		return ;
	}
	printf("%s", pwd_value);
}
