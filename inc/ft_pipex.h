/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:01:10 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/05 11:15:37 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# define CHILD 0

/*
 *------------ft_find_check_access.c
 */
char	*ft_exec(char *cmd_split, char **env);

/*
 *------------ft_fork.c
 */
void	ft_fork_file_failed(void);
void	ft_fork_last(char *cmd, char **env);
void	ft_fork(char *cmd, char **env);

/*
 *------------utils.c
 */
void	ft_exit_fail_param(void);
int		ft_open_file(char *file1, int file_status);
void	ft_close(int fd, int exit);
void	ft_cmd_perror(char *str);
void	ft_clear_all_exec(char **tab, char **cmd, char *exec, int print);

#endif
