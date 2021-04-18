/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:14:00 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/21 12:32:01 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char *str);
void				*ft_calloc(size_t num, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int arg);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dest, const void *orig, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *destination, const void *source,
					size_t num);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *str, char c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *str1);
char				*ft_strjoin(char const *s1,
					char const *s2);
size_t				ft_strlcat(char *restrict dst, const char *restrict
					src, size_t dstsize);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
int					ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)
					(unsigned int, char));
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strnstr(const char *haystack,
					const char *needle, int len1);
char				*ft_strrchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void
					(*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)
					(void *), void (*del)(void *));
char				*ft_strtrim(char const *s1, char const *set);

#endif
