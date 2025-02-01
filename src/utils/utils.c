/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:37:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/01 10:30:23 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <fcntl.h>

void	ft_exit_fail_param(int error)
{
	if (error == 1)
	{
		ft_printf("+-------------------------+\n");
		ft_printf("|  file cmd ... cmd file  |\n");
		ft_printf("+-------------------------+\n");
	}
	if (error == 2)
	{
		ft_printf("+-------------------------------------+\n");
		ft_printf("|  here_doc limiter cmd ... cmd file  |\n");
		ft_printf("+-------------------------------------+\n");
	}
	exit(1);
}

int	ft_open_file(char *file1, char *file2, int *fd_0, int file_status)
{
	int	fd_1;

	if (file_status == 1)
		fd_1 = open(file2, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (file_status == 1 && fd_1 == -1)
		exit(1);
	if (file_status == 1)
		return (fd_1);
	if (file_status == 2)
	{
		*fd_0 = open(file1, O_RDONLY, 0777);
		fd_1 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	if (*fd_0 == -1 || fd_1 == -1)
	{
		ft_close(*fd_0, 0);
		ft_close(fd_1, 1);
	}
	return (fd_1);
}

void	ft_close(int fd, int exiting)
{
	if (fd == -1 || close(fd) == -1)
	{
		perror("Error");
	}
	if (exiting == 1)
		exit(1);
}
