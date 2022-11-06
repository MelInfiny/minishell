/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:42:06 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 15:00:24 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(const char *str);
int				ft_isascii(int caractere);
int				ft_isalnum(int caractere);
int				ft_isalpha(int caractere);
int				ft_isprint(int caractere);
int				ft_isdigit(int caractere);
int				ft_toupper(int caractere);
int				ft_tolower(int caractere);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t n, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_itoa(int n);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s, const char *set);
char			*ft_strchr(const char *s, int caractere);
char			*ft_strrchr(const char *s, int caractere);
char			*ft_strnstr(const char *s, const char *find, size_t size);
char			*ft_strdup(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmapi(const char *s, char (*f) (unsigned int, char));
char			**ft_split(const char *s, char c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);
#endif
