/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:01:10 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/06 14:45:21 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H
# define CHILD 0

/*
 *------------ft_here_doc_bonus.c
 */
void	ft_init_here_doc(char **av);

/*
 *------------ft_fork.c
 */
void	ft_fork_file_failed(void);
int		ft_fork_last(char *cmd, char **env);
void	ft_fork(char *cmd, char **env);

/*
 *------------ft_find_check_access.c
 */
char	*ft_exec(char *cmd_split, char **env);

/*
 *------------ft_open_file.c
 */
int		ft_file_in(char *file);
int		ft_file_out(char *file, int file_status, char *cmd, char **env);
int		ft_open_file(char *file1, int file_status);

/*
 *------------utils.c
 */
void	ft_exit_fail_param(int error);
void	ft_dup(int oldfd, int newfd);
void	ft_close(int fd, int exit);
void	ft_clear_all_exec(char **tab, char **cmd, char *exec, int print);

#endif
