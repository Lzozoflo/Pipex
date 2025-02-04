/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:01:10 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/04 14:54:48 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H
# define CHILD 0

/*
 *------------ft_find_check_access.c
 */
char	*ft_exec(char *cmd_split, char **env);

/*
 *------------ft_here_doc_bonus.c
 */
void	ft_init_here_doc(char **av);
/*
 *------------utils.c
 */
void	ft_exit_fail_param(int error);
int		ft_open_file(char *file1, int file_status);
void	ft_close(int fd, int exit);
void	ft_cmd_perror(char *str);
void	ft_clear_all_exec(char **tab, char **cmd, char *exec, int print);



#endif
