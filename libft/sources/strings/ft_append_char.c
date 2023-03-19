/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_append_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 05:18:43 by fra           #+#    #+#                 */
/*   Updated: 2023/02/11 00:12:32 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_char(char to_add, char **str)
{
	size_t	i;
	size_t	length;
	char	*tmp;

	if (! to_add)
		return (*str);
	length = ft_strlen(*str);
	tmp = malloc((length + 2) * sizeof(char));
	if (! tmp)
		return (NULL);
	i = 0;
	while (str && i < length)
	{
		tmp[i] = (*str)[i];
		i++;
	}
	tmp[i++] = to_add;
	tmp[i] = 0;
	if (str)
		free(*str);
	*str = tmp;
	return (*str);
}
