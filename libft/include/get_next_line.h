/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 05:52:23 by fra           #+#    #+#                 */
/*   Updated: 2023/02/25 05:53:33 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		find_nl_pos(char *str);

int		length_new_str(char *buffer);

int		shift_chars(char *str);

char	*append_str(char *old, char *buffer);

char	*get_next_line(int fd);

#endif