/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:15:52 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/05 11:39:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_fork_file_failed(void)
{
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	ft_close(p_fd[1], 0);
	dup2(p_fd[0], STDIN_FILENO);
	ft_close(p_fd[0], 0);
}

void	ft_fork_last(char *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == CHILD)
		ft_exec(cmd, env);
}

static void	ft_child(char *cmd, char **env, int p_fd0, int p_fd1)
{
	ft_close(p_fd0, 0);
	dup2(p_fd1, STDOUT_FILENO);
	ft_close(p_fd1, 0);
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
	if (pid == CHILD)
		ft_child(cmd, env, p_fd[0], p_fd[1]);
	else
	{
		ft_close(p_fd[1], 0);
		dup2(p_fd[0], STDIN_FILENO);
		ft_close(p_fd[0], 0);
	}
}
