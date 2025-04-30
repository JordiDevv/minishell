/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:18:59 by rhernand          #+#    #+#             */
/*   Updated: 2025/04/30 09:01:15 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Takes 2 strings. Allocates space and joins them together. 
Returns the joined string. If there is an error, returns NULL*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	j;
	size_t	i;
	char	*buff;

	if (!s1 && !s2)
		return (NULL);
	j = 0;
	buff = (char *) malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		buff[i] = s1[i];
		i++;
	}
	while (s2[j])
		buff[i++] = s2[j++];
	buff[i] = '\0';
	return (buff);
}

/* int	main(void)
{
	printf("result ft_strjoin = %s\n", ft_strjoin("pru", "oronga"));
	return (0);
} */