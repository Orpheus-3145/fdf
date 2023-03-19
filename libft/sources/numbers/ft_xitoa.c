/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_xitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 22:35:04 by fra           #+#    #+#                 */
/*   Updated: 2023/03/06 17:13:23 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_xitoa(int n, int capital)
{
	size_t	size;
	char	*str_nbr;
	char	*base;

	size = ft_nbrlen(n, 16);
	str_nbr = (char *) malloc(size + 1);
	if (! str_nbr)
		return (NULL);
	if (capital)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	str_nbr[size--] = '\0';
	if (! n)
		str_nbr[size] = '0';
	while (n)
	{
		str_nbr[size--] = base[n % 16];
		n /= 16;
	}
	return (str_nbr);
}
