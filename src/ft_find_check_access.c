/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_check_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:55:17 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/28 12:36:13 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
// #include <fcntl.h>
// #include <unistd.h>

char	*ft_find_line_env(char *env_name, char **env)
{
	int	len;

	len = ft_strlen(env_name);
	while (env++)
	{
		if (ft_strncmp(env_name, *env, len) == 0)
			return (*env + len + 1);
	}
	exit(0);
}

char	**ft_add_slash(char **tab)
{
	void	*tmp;
	int		i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		tmp = &tab[i];
		tab[i] = ft_strjoin(tab[i], "/");
		free(tmp);
		if (!tab[i])
			return (ft_freetab(tab, 0));
	}
	return (tab);
}

char	*ft_check_acces(char *cmd_to_split, char **env)
{
	char	**cmd;
	char	**tab;
	char	*exec;
	int		i;

	i = -1;
	tab = ft_add_slash(ft_split(ft_find_line_env("PATH", env), ':'));
	if (!tab)
		return (NULL);
	cmd = ft_split_cmd(cmd_to_split);
	if (!cmd)
		return ((void)ft_freetab(tab, 0), NULL);
	while (tab[++i])
	{
		exec = ft_strjoin(tab[i], cmd[0]);
		if (!exec)
			return ((void)ft_freetab(tab, 0), (void)ft_freetab(cmd, 0), NULL);
		if (access(exec, F_OK) == 0)
			return ((void)ft_freetab(tab, 0), (void)ft_freetab(cmd, 0), exec);
		free(exec);
	}
	return (ft_freetab(tab, 0), (void)ft_freetab(cmd, 0), NULL);
}


// char	*ft_check_acces(char *cmd, char **env)
// {
// 	char	**tab;
// 	char	*path;
// 	char	*exec;
// 	int		i;

// 	i = -1;
// 	tab = ft_split(ft_find_line_env("PATH", env), ':');
// 	if (!tab)
// 		return (NULL);
// 	while (tab[++i])
// 	{
// 		path = ft_strjoin(tab[i], "/");
// 		if (!path)
// 			return ((void)ft_freetab(tab, 0), NULL);
// 		exec = ft_strjoin(path, cmd);
// 		free(path);
// 		if (!exec)
// 			return ((void)ft_freetab(tab, 0), NULL);
// 		if (access(exec, F_OK) == 0)
// 			return ((void)ft_freetab(tab, 0), exec);
// 		free(exec);
// 	}
// 	ft_freetab(tab, 0);
// 	return (NULL);
// }
