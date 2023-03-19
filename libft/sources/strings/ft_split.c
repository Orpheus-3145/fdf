/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 01:45:24 by anonymous     #+#    #+#                 */
/*   Updated: 2023/02/27 03:01:30 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	len_substr(char const *str, char char_split)
{
	size_t	length;

	length = 0;
	while (*str && *str++ != char_split)
		length++;
	return (length);
}

char	**ft_split(char const *str, char split)
{
	char	**matrix;
	char	*sub_str;
	size_t	index;

	index = 0;
	if (! str)
		return (NULL);
	matrix = malloc ((ft_n_substr(str, split) + 1) * sizeof(char *));
	if (! matrix)
		ft_raise_error("(ft_split) Memory error", 0);
	while (matrix && *str)
	{
		if (*str != split)
		{
			sub_str = ft_substr(str, 0, len_substr(str, split));
			if (! sub_str)
				return (ft_free_double((void ***) &matrix, index));
			matrix[index++] = sub_str;
			str += ft_strlen(sub_str) - 1;
		}
		str++;
	}
	if (matrix)
		matrix[index] = 0;
	return (matrix);
}
