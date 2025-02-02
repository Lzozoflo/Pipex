/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:37:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/02 10:50:11 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_exit_fail_param(void)
{
	ft_printf("+----------------------------+\n");
	ft_printf("|  file cmd1 cmd2 cmdn file  |\n");
	ft_printf("+----------------------------+\n");
	exit(1);
}

int	ft_open_file(char *file, int file_status)
{
	int	fd;

	fd = 0;
	if (file_status == 0)
		fd = open(file, O_RDONLY, 0777);
	else if (file_status == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
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
		exit(1);
}
