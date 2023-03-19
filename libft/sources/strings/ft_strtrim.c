/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 11:00:40 by faru          #+#    #+#                 */
/*   Updated: 2023/03/06 04:54:49 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include"libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (! str || ! set)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	while (ft_strchr(set, str[start]) && str[start])
		start++;
	while (ft_strrchr(set, str[end]) && end)
		end--;
	if (start > end)
		trimmed = ft_strdup("");
	else
		trimmed = ft_substr(str, start, end - start + 1);
	return (trimmed);
}
