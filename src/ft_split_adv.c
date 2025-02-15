/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_adv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:40:22 by rhernand          #+#    #+#             */
/*   Updated: 2025/02/15 22:16:41 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Takes string s and divides it to different strings separated by 
character c. Returns an array of resulting strings*/

#include "../inc/parser.h"

static char	**ft_mal(const char *s, const char c)
{
	int		words;
	char	**strs;
	int		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i])
		{
			i += ft_markfind((char *)&(s[i]));
			i++;
		}
	}
	strs = (char **) malloc ((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	*(strs + words) = NULL;
	return (strs);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

static void	ft_init(int *i, int *j, int *len)
{
	*i = 0;
	*j = 0;
	*len = 0;
}

static char	**ft_fill(const char *s, const char c, char **strs)
{
	int		len;
	int		i;
	int		j;

	ft_init(&i, &j, &len);
	if (!strs)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i + len] != c && s[i + len])
		{
			len += ft_markfind((char *)&(s[i + len]));
			len++;
		}
		if (s[i])
		{
			strs[j] = ft_substr(s, i, len);
			if (!strs[j])
				return (ft_free(strs));
			j++;
		}
		i = i + len;
		len = 0;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split_adv(const char *s, const char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = ft_fill(s, c, ft_mal(s, c));
	return (ptr);
}

/*int	main(void)
{
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split("       ", ' ');
	while (strs[i])
		printf("%s\n", strs[i++]);
} */
