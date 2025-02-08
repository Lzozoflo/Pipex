/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/08 17:32:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFFER_SIZE 5

static char	*ft_random_name(void)
{
	char	*random;
	int		fd;

	random = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!random)
		exit(1);
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		free(random);
		exit(1);
	}
	read(fd, random, BUFFER_SIZE);
	close(fd);
	return (random);
}

static int	ft_here_doc(int ac, char **av, char **env)
{
	char	*here_doc_name;
	int		status;
	int		i;

	if (ac < 6)
		ft_exit_fail_param(2);
	here_doc_name = ft_random_name();
	i = 3;
	ft_init_here_doc(av, here_doc_name);
	while (i < ac - 2)
		ft_fork(av[i++], env, here_doc_name);
	status = ft_file_out_here(av[ac - 1], av[ac - 2], env, here_doc_name);
	ac -= 5;
	while (ac--)
		waitpid(-1, NULL, WNOHANG);
	unlink(here_doc_name);
	free(here_doc_name);
	return (status);
}

static int	ft_current(int ac, char **av, char **env)
{
	int	status;
	int	i;

	i = 2;
	i += ft_file_in(av[1]);
	while (i < ac - 2)
		ft_fork(av[i++], env, NULL);
	status = ft_file_out(av[ac - 1], av[ac - 2], env, NULL);
	ac -= 4;
	while (ac--)
		waitpid(-1, NULL, WNOHANG);
	return (status);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		ft_exit_fail_param(1);
	else if (ft_strncmp(av[1], "here_doc", 9) == 0)
		return (ft_here_doc(ac, av, env));
	else
		return (ft_current(ac, av, env));
}
