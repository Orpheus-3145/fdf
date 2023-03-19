/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:28:31 by anonymous     #+#    #+#                 */
/*   Updated: 2023/03/06 04:53:52 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*new_str;

	if (! str || ! f)
		return (NULL);
	length = ft_strlen(str);
	new_str = (char *) malloc(length + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[length] = '\0';
	while (length--)
		new_str[length] = f(length, str[length]);
	return (new_str);
}
