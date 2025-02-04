/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/04 15:11:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

void	ft_fork_last(char *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == CHILD)
		ft_exec(cmd, env);
}

void	ft_fork(char *cmd, char **env)
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
		dup2(p_fd[1], STDOUT_FILENO);
		ft_close(p_fd[1], 0);
		ft_exec(cmd, env);
	}
	else
	{
		ft_close(p_fd[1], 0);
		dup2(p_fd[0], STDIN_FILENO);
		ft_close(p_fd[0], 0);
	}
}

/**
 * @brief if ac < 6 we dont have the limiter or only one cmd so not valide
 *
 * 		We dont have a frist file for here_doc because here_doc was fd = 0
 *
 * 		"open_file(av[ac - 1, 2)" if the file are not open wait for not exec
 * 	the last cmd like bash
 *
 */
void	ft_here_doc(int ac, char **av, char **env)
{
	int	waiting;
	int	fd;
	int	i;

	if (ac < 6)
		ft_exit_fail_param(2);
	i = 3;
	waiting = 1;
	ft_init_here_doc(av);
	while (i < ac - 2)
		ft_fork(av[i++], env);
	fd = ft_open_file(av[ac - 1], 2);
	if (fd != -1)
	{
		dup2(fd, STDOUT_FILENO);
		ft_close(fd, 0);
		ft_fork_last(av[ac - 2], env);
	}
	while (waiting != -1)
		waiting = waitpid(-1, NULL, 0);
}

/**
 * @brief "open_file(av[1], 0)" if the file are not open i = 3 for not exec
 * 	the frist cmd like bash
 * 		"open_file(av[ac - 1], 1)" if the file are not open wait for not exec
 * 	the last cmd like bash
 */
void	ft_current(int ac, char **av, char **env)
{
	int	waiting;
	int	fd;
	int	i;

	i = 2;
	waiting = 1;
	fd = ft_open_file(av[1], 0);
	if (fd != -1)
	{
		dup2(fd, STDIN_FILENO);
		ft_close(fd, 0);
	}
	else
		i = 3;
	while (i < ac - 2)
		ft_fork(av[i++], env);
	fd = ft_open_file(av[ac - 1], 1);
	if (fd != -1)
	{
		dup2(fd, STDOUT_FILENO);
		ft_close(fd, 0);
		ft_fork_last(av[ac - 2], env);
	}
	while (waiting != -1)
		waiting = waitpid(-1, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		ft_exit_fail_param(1);
	else if (ft_strncmp(av[1], "here_doc", 8) == 0)
		ft_here_doc(ac, av, env);
	else
		ft_current(ac, av, env);
	return (0);
}
