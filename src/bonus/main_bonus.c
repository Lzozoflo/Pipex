/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/06 14:16:42 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

static int	ft_here_doc(int ac, char **av, char **env)
{
	int	i;

	if (ac < 6)
		ft_exit_fail_param(2);
	i = 3;
	ft_init_here_doc(av);
	while (i < ac - 2)
		ft_fork(av[i++], env);
	return (ft_file_out(av[ac - 1], 2, av[ac - 2], env));
}

static int	ft_current(int ac, char **av, char **env)
{
	int	i;

	i = 2;
	i += ft_file_in(av[1]);
	while (i < ac - 2)
		ft_fork(av[i++], env);
	return (ft_file_out(av[ac - 1], 1, av[ac - 2], env));
}

int	main(int ac, char **av, char **env)
{
	int	waiting;
	int	status;

	status = 0;
	if (ac < 5)
		ft_exit_fail_param(1);
	else if (ft_strncmp(av[1], "here_doc", 8) == 0)
		status = ft_here_doc(ac, av, env);
	else
		status = ft_current(ac, av, env);
	waiting = 1;
	while (waiting != -1)
		waiting = waitpid(-1, NULL, 0);
	ft_printf("%d", status);
	return (status);
}
