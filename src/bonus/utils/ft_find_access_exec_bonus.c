/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_access_exec_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:55:17 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/08 10:07:43 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include "libft.h"

static char	*ft_find_line_env(char *env_name, char **env)
{
	size_t	len;

	len = ft_strlen(env_name);
	while (env++)
	{
		if (ft_strncmp(env_name, *env, len) == 0)
			return (*env + len + 1);
	}
	exit(0);
}

static char	**ft_add_slash(char **tab)
{
	void	*tmp;
	int		i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i] && tab[i][0])
	{
		tmp = &tab[i][0];
		tab[i] = ft_strjoin(tab[i], "/");
		free(tmp);
		if (!tab[i])
			return (ft_freetab(tab, 0));
		i++;
	}
	return (tab);
}

static char	*ft_exec_path(char **cmd, char **tab, char **env)
{
	char	*exec;
	int		i;

	i = -1;
	while (tab[++i])
	{
		exec = ft_strjoin(tab[i], cmd[0]);
		if (!exec)
		{
			ft_clear_all_exec(tab, cmd, NULL, 0);
			exit(1);
		}
		if (access(exec, F_OK | X_OK) == 0)
		{
			execve(exec, cmd, env);
			ft_clear_all_exec(tab, cmd, exec, 0);
			exit(1);
		}
		free(exec);
	}
	ft_clear_all_exec(tab, cmd, NULL, 1);
	exit(127);
}

char	*ft_exec(char *cmd_split, char **env)
{
	char	**cmd;
	char	**tab;

	cmd = ft_split(cmd_split, ' ');
	if (!cmd)
		exit(1);
	if (access(cmd[0], F_OK | X_OK) == 0)
	{
		execve(cmd[0], cmd, env);
		ft_clear_all_exec(NULL, cmd, NULL, 0);
		exit(126);
	}
	tab = ft_add_slash(ft_split(ft_find_line_env("PATH", env), ':'));
	if (!tab)
	{
		ft_freetab(cmd, 0);
		exit(1);
	}
	ft_exec_path(cmd, tab, env);
	exit(127);
}
