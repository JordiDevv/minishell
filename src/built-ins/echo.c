/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:57:27 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/17 12:02:18 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/parser.h"

void	ex_echo(char *txt)
{
	if (!txt)
	{
		printf(Y "Error: problem ejecuting echo" RE);
		return ;
	}
	printf("%s\n", txt);
}
