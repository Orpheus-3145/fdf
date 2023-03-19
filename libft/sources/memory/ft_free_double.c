/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_double.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 22:18:30 by fra           #+#    #+#                 */
/*   Updated: 2023/02/25 06:50:59 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_double(void ***to_free, int n_arr)
{
	int		i;
	char	***tmp;

	if (to_free && *to_free)
	{
		i = 0;
		if (n_arr == -1)
		{
			tmp = (char ***) to_free;
			while ((*tmp)[i])
				free((*tmp)[i++]);
			free(*tmp);
		}
		else
		{
			while (i < n_arr)
				free((*to_free)[i++]);
			free(*to_free);
		}
	}
	return (NULL);
}
