/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:37:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/06 14:43:14 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <fcntl.h>

void	ft_exit_fail_param(int error)
{
	if (error == 1)
	{
		ft_printf("+--------------------------------+\n");
		ft_printf("|  file cmd1 cmd2 ... cmdn file  |\n");
		ft_printf("+--------------------------------+\n");
	}
	if (error == 2)
	{
		ft_printf("+--------------------------------------------+\n");
		ft_printf("|  here_doc limiter cmd1 cmd2 ... cmdn file  |\n");
		ft_printf("+--------------------------------------------+\n");
	}
	exit(2);
}

void	ft_dup(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		perror("dup2 fail");
		ft_close(oldfd, 0);
		exit(1);
	}
	ft_close(oldfd, 0);
}

void	ft_close(int fd, int exiting)
{
	close(fd);
	if (exiting == 1)
	{
		perror("fork fail");
		exit(1);
	}
}

static void	ft_cmd_perror(char *str)
{
	char	*rstr;
	char	*tmp;

	tmp = ft_strjoin("command not found: ", str);
	if (!tmp)
	{
		perror("Failure in error handling\n");
		return ;
	}
	rstr = ft_strjoin(tmp, "\n");
	free(tmp);
	if (!rstr)
	{
		perror("Failure in error handling\n");
		return ;
	}
	ft_putstr_fd(rstr, 2);
	free(rstr);
}

void	ft_clear_all_exec(char **tab, char **cmd, char *exec, int print)
{
	if (print == 1)
		ft_cmd_perror(cmd[0]);
	if (tab)
		ft_freetab(tab, 0);
	if (cmd)
		ft_freetab(cmd, 0);
	if (exec)
		free(exec);
}
