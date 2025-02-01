/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/01 10:49:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

void	ft_open_here_doc(char **av, int p_fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, p_fd);
		free(line);
	}
}

void	ft_here_doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
	{
		ft_close(p_fd[0], 0);
		ft_close(p_fd[1], 1);
	}
	else if (!pid)
	{
		ft_close(p_fd[0], 0);
		ft_open_here_doc(av, p_fd[1]);
	}
	else
	{
		ft_close(p_fd[1], 0);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

void	ft_init_here_doc(int ac, char **av, int *fd_1)
{
	if (ac < 6)
		ft_exit_fail_param(2);
	*fd_1 = ft_open_file(NULL, av[ac - 1], NULL, 1);
	ft_here_doc(av);
}

void	ft_fork(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
	{
		ft_close(p_fd[0], 0);
		ft_close(p_fd[1], 1);
	}
	else if (!pid)
	{
		ft_close(p_fd[0], 0);
		dup2(p_fd[1], 1);
		ft_close(p_fd[1], 0);
		ft_exec(cmd, env);
	}
	else
	{
		ft_close(p_fd[1], 0);
		dup2(p_fd[0], 0);
		ft_close(p_fd[0], 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fd_0;
	int		fd_1;
	int		i;

	if (ac < 5)
		ft_exit_fail_param(2);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		ft_init_here_doc(ac, av, &fd_1);
		i = 3;
	}
	else
	{
		fd_1 = ft_open_file(av[1], av[ac - 1], &fd_0, 2);
		dup2(fd_0, 0);
		ft_close(fd_0, 0);
		i = 2;
	}
	while (i < ac - 2)
		ft_fork(av[i++], env);
	dup2(fd_1, 1);
	ft_close(fd_1, 0);
	ft_exec(av[ac - 2], env);
}
