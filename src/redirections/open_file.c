/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:50:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/01/22 12:36:23 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	open_file(char *file, char redirection)
{
	int	fd;

	fd = -1;
	if (access(file, F_OK))
	{
		printf(Y "-bash: %s: %s\n" RE, file, strerror(errno));
		return (-1);
	}
	else
	{
		if (redirection == '>')
			fd = open(file, O_RDONLY);
		else if (redirection == '<')
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	}
	if (fd < 0)
	{
		perror(R "Error opening, or creating, one redirection file\n" RE);
		return (-1);
	}
	return (fd);
}
