/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:37:42 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/03 17:57:38 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif
# ifndef FD_MAX
#  define FD_MAX 256
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef unsigned long	t_size;

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strnstr(char *haystack, char *needle, t_size len);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, t_size n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(void *s1, void *s2, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f) (unsigned int, char));
void		ft_striteri(const char *s, void (*f) (unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strtrim(const char *s1, const char *set);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del) (void *));
void		ft_lstclear(t_list **lst, void (*del) (void *));
void		ft_lstiter(t_list *lst, void (*f) (void *));
t_list		*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
char		*ft_get_next_line(int fd);

#endif
