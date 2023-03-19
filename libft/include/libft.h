/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 15:17:04 by anonymous     #+#    #+#                 */
/*   Updated: 2023/03/12 06:04:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include<stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalnum(int a);

int		ft_isalpha(int a);

int		ft_isascii(int a);

int		ft_isdigit(int a);

int		ft_ishexadigit(int c);

int		ft_isprint(int a);

int		ft_isspace(char c);

int		ft_toupper(int a);

int		ft_tolower(int a);

int		ft_is_number(char *n);

int		ft_is_int(char *number);

int		ft_is_long(char *number);

size_t	ft_putchar_fd(char a, int b);

size_t	ft_putstr_fd(char *a, int b);

size_t	ft_putendl_fd(char *a, int b);

size_t	ft_putnbr_fd(int a, int b);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_bzero(void *a, size_t b);

void	*ft_calloc(size_t a, size_t b);

void	*ft_free_single(void **to_free);

void	*ft_free_double(void ***to_free, int n_arr);

void	*ft_memchr(const void *str_to_search, int to_find, size_t n);

int		ft_memcmp(const void *src, const void *dst, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *str, int to_write, size_t n);

void	ft_raise_error(char *text, int end);

float	ft_atof(const char *str);

int		ft_atoi(const char *a);

long	ft_atol(const char *a);

char	ft_bin_to_char(int *bin_char, size_t bits);

void	ft_char_to_bin(char c, int *bin_char, size_t bits);

char	*ft_itoa(int a);

char	*ft_litoa(long a);

float	ft_mod(float a);

size_t	ft_nbrlen(size_t nbr, int base);

float	ft_part_dec(float number);

float	ft_part_int(float number);

int		ft_round_to_int(double number);

float	ft_pow(int base, int exp);

float	ft_xatof(char *str_n);

int		ft_xatoi(char *str);

char	*ft_xitoa(int a, int capital);

char	*ft_append_char(char to_add, char **str);

int		ft_count_occ(char *str, char to_find);

int		ft_find_index(char *str, char value);

size_t	ft_n_substr(char const *str, char char_split);

char	**ft_split(char const *str, char split);

char	*ft_strchr(const char *str_to_search, int to_find);

char	*ft_strdup(const char *str);

void	ft_striteri(char *str, void (*f)(unsigned int, char*));

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));

int		ft_strncmp(const char *str1, const char *str2, size_t n);

char	*ft_strnstr(const char *str, char *to_find, size_t len);

char	*ft_strrchr(const char *str_to_search, int to_find);

char	*ft_strtrim(char const *str, char const *set);

char	*ft_substr(const char *str, unsigned int start, size_t len);

#endif
