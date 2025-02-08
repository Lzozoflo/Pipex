/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/08 17:17:15 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

static int	ft_current(int ac, char **av, char **env)
{
	int	status;
	int	i;

	i = 2;
	i += ft_file_in(av[1]);
	while (i < ac - 2)
		ft_fork(av[i++], env);
	status = ft_file_out(av[ac - 1], av[ac - 2], env);
	ac -= 4;
	while (ac--)
		waitpid(-1, NULL, WNOHANG);
	return (status);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		ft_exit_fail_param();
	else
		return (ft_current(ac, av, env));
}
