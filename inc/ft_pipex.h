/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:01:10 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/28 12:25:01 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PIPEX_H
# define FT_PIPEX_H


typedef struct s_file
{
	char		*one;
	char		*two;
	int			fd1;
	int			fd2;
}				t_file;


/*
 *------------ft_find_check_access.c
 */
char	*ft_check_acces(char *cmd, char **env);
char	**ft_split_cmd(char const *s);


#endif
