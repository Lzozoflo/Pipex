/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/05 11:03:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

/**
 * @brief "open_file(av[1], 0)" if the file are not open i = 3 for not exec
 * 	the frist cmd like bash
 * 		"open_file(av[ac - 1], 1)" if the file are not open wait for not exec
 * 	the last cmd like bash
 */
void	ft_current(int ac, char **av, char **env)
{
	int	fd;
	int	i;

	i = 2;
	fd = ft_open_file(av[1], 0);
	if (fd != -1)
	{
		dup2(fd, STDIN_FILENO);
		ft_close(fd, 0);
	}
	else
	{
		ft_fork_file_failed();
		i = 3;
	}
	while (i < ac - 2)
		ft_fork(av[i++], env);
	fd = ft_open_file(av[ac - 1], 1);
	if (fd != -1)
	{
		dup2(fd, STDOUT_FILENO);
		ft_close(fd, 0);
		ft_fork_last(av[ac - 2], env);
	}
}

int	main(int ac, char **av, char **env)
{
	int	waiting;

	if (ac != 5)
		ft_exit_fail_param();
	else
		ft_current(ac, av, env);
	waiting = 1;
	while (waiting != -1)
		waiting = waitpid(-1, NULL, 0);
	return (0);
}
