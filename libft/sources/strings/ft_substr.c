/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 11:00:52 by faru          #+#    #+#                 */
/*   Updated: 2023/02/27 02:54:13 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	lenght_str;

	if (! str)
		return (NULL);
	lenght_str = ft_strlen(str);
	if (start > lenght_str)
		return (ft_strdup(""));
	if (start + len > lenght_str)
		len = lenght_str - start;
	sub_str = (char *) malloc(len + 1);
	if (! sub_str)
		ft_raise_error("(ft_substr) Memory error", 0);
	else
		ft_strlcpy(sub_str, str + start, len + 1);
	return (sub_str);
}
