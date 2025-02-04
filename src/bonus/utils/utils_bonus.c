/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:37:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/04 08:48:53 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	exit(1);
}

int	ft_open_file(char *file, int file_status)
{
	int	fd;

	fd = 0;
	if (file_status == 0)
		fd = open(file, O_RDONLY);
	else if (file_status == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (file_status == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		ft_printf("bash: %s: ", file);
		perror("");
	}
	return (fd);
}

void	ft_close(int fd, int exiting)
{
	close(fd);
	if (exiting == 1)
	{
		ft_putstr_fd("fail fork");
		exit(1);
	}
}

void	ft_cmd_perror(char *str)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
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
