/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:47:39 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/01 12:53:26 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
//#include <stdio.h>

char	*ft_update_stack(char *stack)
{
	char	*new_stack;
	char	*aux;
	size_t	i;

	i = 0;
	new_stack = ft_strchr(stack, '\n');
	if (!new_stack)
		return (free(stack), stack = NULL, NULL);
	new_stack++;
	aux = malloc((ft_strlen(new_stack) + 1) * sizeof(char));
	if (!aux)
		return (free(stack), stack = NULL, NULL);
	while (new_stack[i])
	{
		aux[i] = new_stack[i];
		i++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*ft_create_line(char *stack)
{
	size_t	pos;
	char	*line;

	if (!stack || !*stack)
		return (NULL);
	pos = 0;
	while (stack[pos] && stack[pos] != '\n')
		pos++;
	if (stack[pos] == '\n')
		pos++;
	line = malloc((pos + 1) * sizeof (char));
	if (!line)
		return (NULL);
	pos = 0;
	while (stack[pos] && stack[pos] != '\n')
	{
		line[pos] = stack[pos];
		pos++;
	}
	if (stack[pos] == '\n')
		line[pos++] = '\n';
	line[pos] = '\0';
	return (line);
}

char	*ft_join(char *str1, char *str2)
{
	char	*aux;

	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	if (!str1)
		return (NULL);
	aux = ft_strjoin(str1, str2);
	free(str1);
	return (aux);
}

char	*ft_get_next_line(int fd)
{
	static char	*stack[FD_MAX] = {NULL};
	char		*line;
	char		*tmp;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	read_bytes = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (read_bytes > 0 && !(ft_strchr(stack[fd], '\n')))
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(stack[fd]), stack[fd] = NULL, free(tmp), NULL);
		tmp[read_bytes] = '\0';
		stack[fd] = ft_join(stack[fd], tmp);
		if (!stack[fd])
			return (free(tmp), NULL);
	}
	line = ft_create_line(stack[fd]);
	stack[fd] = ft_update_stack(stack[fd]);
	return (free(tmp), line);
}
/*int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY, 0);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/