/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:01:10 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/01 10:06:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

typedef struct s_pipex
{
	int		file1;
	int		file2;
}					t_pipex;

/*
 *------------ft_find_check_access.c
 */
char	*ft_find_line_env(char *env_name, char **env);
char	*ft_exec(char *cmd_split, char **env);
char	**ft_split_cmd(char const *s);

/*
 *------------utils.c
 */
void	ft_exit_fail_param(int error);
int	ft_open_file(char *file1, char *file2, int *fd_0, int file_status);
// int		ft_open_file(char *file, int file_status);
void	ft_close(int fd, int exit);



#endif
