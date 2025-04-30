/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:45:27 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/09 19:35:37 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*Cuts chars contained in string set from the beggining
and the end of string s1. Stops cutting when it finds a character
that is not in string set. 
Allocates space and returns resulting string*/

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	str = 0;
	if (!s1 || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (!set || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (s1 && ft_strchr(set, s1[start]))
		start++;
	while (s1 && ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_substr(s1, start, end - start);
	if (!str)
		return (NULL);
	return (str);
}

/* int	main(void)
{
	char	s[] = "HelloW";
	char	set[] = "HeWo";

	printf("ft_strtrim result = %s\n", ft_strtrim(s, set));
	return (0);
} */
