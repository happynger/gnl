/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:02:50 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/01 20:51:54 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <limits.h>

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

# define SWAP(a,b) a^=b, b^=a, a^=b
# define CHECK_NULL_GNL(x) if ((x) == NULL) return (-1)
# define CHECK_NULL(x) if ((x) == NULL) return (NULL)

typedef int				t_bool;

typedef struct			s_list
{
	char				*content;
	int					fd;
	int					br;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					*ft_memset(void *b, int c, size_t len);
void					*ft_mempcpy(void *dst, const void *src, size_t n);
void					*ft_realloc(void *data,
						size_t data_size, size_t new_size);
char					*ft_strappend(char *dst, const char *src,
						size_t dst_len, size_t src_len);
void					*ft_memccpy(void *dst,
						const void *src, int c, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
int						ft_isdigit(int c);
void					ft_putchar(char c);
void					ft_putstr(const char *str);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_reverse(char *str);
char					*ft_itoa(int nb);
char					*ft_itoa_b(int nb, int base);
size_t					ft_intlen(long nb);
void					ft_putnbr(long i);
int						ft_strequ(const char *s1, const char *s2);
char					*ft_strnew(size_t size);
void					ft_strdel(char **str);
void					ft_strclr(char *str);
void					ft_striter(char *s, void (*f)(char *));
char					*ft_strmap(const char *s, char (*f)(char));
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst,
						const void *src, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					ft_striteri(char *s,
						void (*f)(unsigned int, char *));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
						unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(long n, int fd);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
int						ft_iswhite(int c);
int						ft_isupper(int c);
int						ft_isprint(int c);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_atoi(const char *str);
char					*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
void					ft_bzero(void *s, size_t n);
int						ft_isascii(int c);
void					ft_strclr(char *str);
void					ft_strdel(char **str);
void					ft_striter(char *s, void (*f)(char *));
size_t					ft_strnlen(const char *s, size_t maxlen);
char					*ft_checkdenom(const char *str, char d);
char					*ft_getenv(const char *name);
char					*ft_pathcombine(char *p);

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstaddend(t_list **alst, t_list *new);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
