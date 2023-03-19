/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 11:19:15 by faru          #+#    #+#                 */
/*   Updated: 2023/02/27 03:19:03 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	index;

	index = 0;
	while (str1[index] && str2[index] && index < n)
	{
		if (str1[index] != str2[index])
			return (-1);
		index++;
	}
	if (index == n || (! str1[index] && ! str2[index]))
		return (0);
	else
		return (-1);
}
