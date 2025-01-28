/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/27 08:55:40 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

// int	ft_init(t_file *file, int ac, char **av)
// {
// 	file->one = &av[1];
// 	file->two = &av[ac - 1];
// 	file->fd1 = open(file->one, O_RDONLY);
// 	if (file->fd1 == -1)
// 	{
// 		perror("Error opening file1");
// 		return (0);
// 	}
// 	file->fd1 = open(file->two, O_CREAT | O_TRUNC | O_WRONLY);
// 	if (file->fd2 == -1)
// 	{
// 		perror("Error opening or creating file1");
// 		close(file->fd1);
// 		return (0);
// 	}
// 	return (1);
// }



int	main(int ac, char **av, char **env)
{
	// t_file	file;
	// pid_t	pid;
	// int		i;

	// i = 1;
	// if (ac < 5)
	// 	return (0);

	// if (!ft_init(&file, ac, av))
	// 	return (0);

	// while (i < ac -2)
	// 	ft_idk(av[i], env);

	printf("%s\n\n",ft_find_line_env("PATH", env));

	printf("%s",ft_check_acces(av[1] , env));

	// close(file.fd1);
	// close(file.fd2);
}


