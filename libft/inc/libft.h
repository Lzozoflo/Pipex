/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:34:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/28 12:32:16 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// is Directorie
int			ft_is_white_space(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
char		ft_is_str_digit(char *str);
int			ft_digit_sign(char *str);
int			ft_digit_sign_float(char *str);
int			ft_isprint(int c);

// lst Directorie
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_delete_content(int content);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

// mem Directorie
int			*ft_atoi_alloc(char *str);
void		ft_bzero(void *p, size_t c);
void		*ft_calloc(size_t nb, size_t es);
void		*ft_memchr(const void *p, int v, size_t n);
int			ft_memcmp(const void *p1, const void *p2, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
void		*ft_memset(void *p, int v, size_t c);

// print Directorie
int			ft_printf(const char *format, ...);
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_putchar(char c);
ssize_t		ft_putendl_fd(char *s, int fd);
ssize_t		ft_putendl(char *s);
ssize_t		ft_putnbr_fd(int n, int fd);
ssize_t		ft_putnbr(int n);
int			ft_putnbr_base(int nbr, int base, const char format);
int			ft_putnbr_base_unsign(unsigned long nbr, int base, const char f);
ssize_t		ft_putstr_fd(char *s, int fd);
ssize_t		ft_putstr(char *s);

// string Directorie
char		**ft_split(char const *s, char c);
char		**ft_freetab(char **tab, unsigned int j);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_reajoin(char *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *str1, const char *str2, size_t len);
char		*ft_strnstr(const char *str, const char *cmp, size_t len);
char		*ft_strrchr(const char *str, int search_char);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int i, size_t len);
char		*get_next_line(int fd);

// utility Directorie
int			ft_atoi(const char *str);
long int	ft_atol(const char *str);
double		ft_atod(const char *str);
int			ft_size_base(int nbr, int base);
char		ft_convert_base(unsigned long nbr, int base, const char format);
char		*ft_itoa(int n);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
