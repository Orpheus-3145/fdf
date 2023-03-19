/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_to_bin.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 19:25:36 by fra           #+#    #+#                 */
/*   Updated: 2023/02/11 00:13:04 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char_to_bin(char c, int *bin_char, size_t bits)
{
	char	*base;

	base = "01";
	while (bits--)
	{
		bin_char[bits] = base[c % 2] - '0';
		c /= 2;
	}
}
