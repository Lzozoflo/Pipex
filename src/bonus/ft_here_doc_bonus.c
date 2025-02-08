/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:49:59 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/08 17:32:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

static char	*ft_bash_file_error(char *str1)
{
	char	*rstr;
	char	*tmp;

	tmp = ft_strjoin("bash: ", str1);
	if (!tmp)
	{
		perror("Failure in error handling\n");
		return (NULL);
	}
	rstr = ft_strjoin(tmp, ":");
	free(tmp);
	if (!rstr)
	{
		perror("Failure in error handling\n");
		return (NULL);
	}
	return (rstr);
}

static int	ft_link_file_to_pipe(int p_fd, char *file_name)
{
	char	*bash_error;
	int		fd;

	bash_error = NULL;
	fd = open(file_name, O_RDWR | O_CREAT, 0777);
	if (fd == -1)
	{
		if (file_name)
		{
			bash_error = ft_bash_file_error(file_name);
			free(file_name);
			if (!bash_error)
				exit(1);
		}
		perror(bash_error);
		free(bash_error);
		free(file_name);
		exit(1);
	}
	ft_dup(p_fd, fd);
	return (fd);
}

static int	ft_open_here_doc(char **av, int p_fd, char *file_name)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = ft_link_file_to_pipe(p_fd, file_name);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		if (!line)
			return (-1);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0
			&& ft_strlen(av[2]) + 1 == ft_strlen(line))
		{
			free(file_name);
			free(line);
			ft_close(fd, 0);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	exit(0);
}

void	ft_init_here_doc(char **av, char *here_doc_name)
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
		ft_open_here_doc(av, p_fd[1], here_doc_name);
	}
	else
	{
		ft_close(p_fd[1], 0);
		waitpid(pid, NULL, 0);
		ft_dup(p_fd[0], STDIN_FILENO);
	}
}
