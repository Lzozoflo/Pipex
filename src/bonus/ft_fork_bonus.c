/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:15:52 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/08 17:27:49 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_fork_file_failed(void)
{
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	ft_close(p_fd[1], 0);
	ft_dup(p_fd[0], STDIN_FILENO);
}

int	ft_fork_last(char *cmd, char **env, char *file_name)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == CHILD)
	{
		if (file_name)
			free(file_name);
		ft_exec(cmd, env);
	}
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

static void	ft_child(char *cmd, char **env, int p_fd0, int p_fd1)
{
	ft_close(p_fd0, 0);
	ft_dup(p_fd1, STDOUT_FILENO);
	ft_exec(cmd, env);
}

void	ft_fork(char *cmd, char **env, char *file_name)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
	{
		if (file_name)
			free(file_name);
		ft_close(p_fd[0], 0);
		ft_close(p_fd[1], 1);
	}
	if (pid == CHILD)
	{
		if (file_name)
			free(file_name);
		ft_child(cmd, env, p_fd[0], p_fd[1]);
	}
	else
	{
		ft_close(p_fd[1], 0);
		ft_dup(p_fd[0], STDIN_FILENO);
	}
}
