/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:10:24 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/08 14:01:23 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <fcntl.h>

static char	*ft_bash_file_error(char *str1)
{
	char	*rstr;
	char	*tmp;

	tmp = ft_strjoin("bash: ", str1);
	if (!tmp)
	{
		perror("Failure in error handling\n");
		return (NULL);
	}
	rstr = ft_strjoin(tmp, ":");
	free(tmp);
	if (!rstr)
	{
		perror("Failure in error handling\n");
		return (NULL);
	}
	return (rstr);
}

int	ft_file_in(char *file)
{
	char	*bash_error;
	int		fd;

	bash_error = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		if (!file)
		{
			bash_error = ft_bash_file_error(file);
			if (!bash_error)
				exit(1);
		}
		perror(bash_error);
		free(bash_error);
		ft_fork_file_failed();
		return (1);
	}
	else
		ft_dup(fd, STDIN_FILENO);
	return (0);
}

int	ft_file_out(char *file, char *cmd, char **env)
{
	char	*bash_error;
	int		fd;

	bash_error = NULL;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (!file)
		{
			bash_error = ft_bash_file_error(file);
			if (!bash_error)
				exit(1);
		}
		perror(bash_error);
		free(bash_error);
		ft_fork_file_failed();
		return (1);
	}
	else
	{
		ft_dup(fd, STDOUT_FILENO);
		return (ft_fork_last(cmd, env));
	}
}
