/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/05 03:45:51 by fra           #+#    #+#                 */
/*   Updated: 2023/03/05 04:28:47 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

float	ft_atof(const char *str_n)
{
	int		i;
	float	nbr;
	int		sign;
	int		comma_pos;

	i = 0;
	nbr = 0;
	sign = 1;
	comma_pos = -1;
	while (ft_isspace(str_n[i]))
		str_n++;
	if (str_n[i] == '-')
	{
		sign = -1;
		str_n++;
	}
	else if (str_n[i] == '+')
		str_n++;
	while (ft_isdigit(str_n[i]))
		nbr = (nbr * 10) + (str_n[i++] - '0');
	if (str_n[i] == ',' || str_n[i] == '.')
		comma_pos = i++;
	while (ft_isdigit(str_n[i]))
		nbr = (nbr * 10) + (str_n[i++] - '0');
	nbr *= sign;
	if (comma_pos != -1)
		nbr *= ft_pow(10, comma_pos - i + 1);
	return (nbr);
}