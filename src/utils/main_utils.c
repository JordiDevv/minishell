/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:05:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/04/29 13:21:57 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

/*void	ft_print_list(t_msh *msh)
{
	t_list	*aux;
	int		i;
	int		j;

	i = 0;
	j = 1;
	aux = msh->lst;
	while (aux)
	{
		printf("\ncommand number %d\n", j);
		printf("cmd built =  %s\n", ((t_cmd *) aux->content)->built);
		printf("cmd full =  %s\n", ((t_cmd *) aux->content)->full);
		printf("cmd input =  %s\n", ((t_cmd *) aux->content)->input);
		printf("cmd del =  %s\n", ((t_cmd *) aux->content)->del);
		printf("cmd output =  %s\n", ((t_cmd *) aux->content)->output);
		printf("cmd append =  %s\n", ((t_cmd *) aux->content)->append);
		while (((t_cmd *)aux->content)->split \
			&& ((t_cmd *)aux->content)->split[i])
		{
			printf("split %d = %s\n", i, ((t_cmd *) aux->content)->split[i]);
			i++;
		}
		i = 0;
		j++;
		aux = aux->next;
	}
}*/
/*Just an ASCII artpiece to know we entered MINISHELL*/

void	ft_draw(void)
{
	const char	*ascii = \
	"         _nnnn_\n" \
	"        dGGGGMMb     ,\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n" \
	"       @p~qp~~qMb    |     MINISHELL     |\n" \
	"       M|@||@) M|    | jsanz-bo rhernand |\n" \
	"       @,----.JM| -'_;...................'\n" \
	"      JS^\\__/  qKL\n" \
	"     dZP        qKRb\n" \
	"    dZP          qKKb\n" \
	"   fZP            SMMb\n" \
	"   HZM            MMMM\n" \
	"   FqM            MMMM\n" \
	" __| \".        |\\dS\"qML\n" \
	" |    `.       | `' \\Zq\n" \
	"_)      \\.___.|     .'\n" \
	"\\____   )MMMMMM|   .'\n" \
	"     `-'       `--'\n";

	printf("%s\n", ascii);
}
