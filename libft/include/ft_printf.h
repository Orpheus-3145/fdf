/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 23:49:07 by anonymous     #+#    #+#                 */
/*   Updated: 2023/02/11 02:04:07 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

int		ft_printf(const char *str, ...);

size_t	print_ph(va_list *ptr, char ph, char flag);

int		check_char(char to_check, char *str_check);

int		check_str(const char *str);

size_t	print_int(int to_print, char flag);

size_t	print_uint(unsigned int to_print);

size_t	print_hex(unsigned int to_print, int capital, char flag);

size_t	print_str(char *to_print);

size_t	print_ptr(size_t to_print);

#endif
