/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:48:10 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/05/11 20:41:49 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void	last_dir(t_msh *msh)
{
	char	*newpwd;
	int		i;

	i = locate_var(msh->env, "OLDPWD");
	if (!msh->env[i][7])
	{
		write (2, "bash: cd: OLDPWD not set\n", 25);
		return ;
	}
	newpwd = malloc((ft_strlen(msh->env[i] + 7) + 1) * sizeof(char));
	if (!newpwd)
		return ;
	ft_strlcpy(newpwd, msh->env[i] + 7, ft_strlen(msh->env[i] + 7) + 1);
	if (chdir(newpwd) < 0)
		perror(newpwd);
	else
	{
		write(1, newpwd, ft_strlen(newpwd));
		write(1, "\n", 1);
	}
	free(newpwd);
}

static void	father_dir(void)
{
	char	*newpwd;
	char	*pwd;
	char	*last_slash;
	int		len;

	pwd = getcwd(NULL, 0);
	last_slash = ft_strrchr(pwd, '/');
	len = last_slash - pwd;
	newpwd = malloc((len + 1) * sizeof(char));
	if (!newpwd)
		return ;
	ft_strlcpy(newpwd, pwd, len + 1);
	if (!newpwd)
		return ;
	if (chdir(newpwd) < 0)
		perror(newpwd);
	if (pwd)
		free(pwd);
	if (newpwd)
		free(newpwd);
}

int	relative_args(t_cmd *cmd, t_msh *msh)
{
	if (!ft_strncmp(cmd->split[1], "-", ft_strlen(cmd->split[1])))
	{
		last_dir(msh);
		return (1);
	}
	else if (!ft_strncmp(cmd->split[1], "..", ft_strlen(cmd->split[1])))
	{
		father_dir();
		return (1);
	}
	return (0);
}
