/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:54:40 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/10 10:23:51 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

extern	int		ft_isalpha(int c);
extern	int		ft_isdigit(int c);
extern	int		ft_isalnum(int c);
extern	int		ft_isascii(int c);
extern	int		ft_isprint(int c);
extern	size_t	ft_strlen(const char *str);
extern	size_t	ft_strlcpy(char *dest, const char *src, size_t size);
extern	size_t	ft_strlcat(char *dest, const char *src, size_t size);
extern	int		ft_toupper(int c);
extern	int		ft_tolower(int c);
extern	int		ft_strncmp(char *s1, const char *s2, size_t n);
extern	long		ft_atoi(const char *str);
extern	int		ft_memcmp(const void *s1, const void *s2, size_t n);
extern	void		ft_bzero(void *s, size_t n);
extern	void		*ft_memset(void *b, int c, size_t len);
extern	void		*ft_calloc(size_t count, size_t size);
extern	void		*ft_memcpy(void *dst, const void *src, size_t n);
extern	void		*ft_memmove(void *dst, const void *src, size_t n);
extern	void		*ft_memchr(const void *s, int c, size_t n);
extern	char		*ft_strdup(const char *s1);
extern	char		*ft_strchr(const char *s, int c);
extern	char		*ft_strrchr(const char *s, int c);
extern	char		*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

char			*ft_substr(const char *s, size_t start, size_t size);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
