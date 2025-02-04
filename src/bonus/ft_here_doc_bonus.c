/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:49:59 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/04 15:06:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

void	ft_open_here_doc(char **av, int p_fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		if (line && ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			ft_close(p_fd, 1);
			break ;
		}
		ft_putstr_fd(line, p_fd);
		free(line);
	}
}

void	ft_init_here_doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
	{
		ft_close(p_fd[0], 0);
		ft_close(p_fd[1], 1);
	}
	else if (pid == CHILD)
	{
		ft_close(p_fd[0], 0);
		ft_open_here_doc(av, p_fd[1]);
	}
	else
	{
		ft_close(p_fd[1], 0);
		dup2(p_fd[0], STDIN_FILENO);
		ft_close(p_fd[0], 0);
	}
}
