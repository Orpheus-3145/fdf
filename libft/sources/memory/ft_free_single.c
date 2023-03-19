/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_single.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 18:32:15 by fra           #+#    #+#                 */
/*   Updated: 2023/03/08 02:16:21 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_single(void **to_free)
{
	if (to_free && *to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (NULL);
}
