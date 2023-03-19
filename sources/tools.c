/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 18:38:04 by faru          #+#    #+#                 */
/*   Updated: 2023/03/19 03:56:50 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	check_input(int argc, char **argv, uint32_t *cols, uint32_t *rows)
{
	char		*file_name;
	int32_t		fd;

	if (argc != 2 || ! ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (false);
	else
		file_name = argv[1];
	*rows = 0;
	*cols = 0;
	fd = open(file_name, O_RDONLY);
	parse_file(fd, cols, rows);
	close(fd);
	return (*rows && *cols);
}

void	parse_file(int32_t fd, uint32_t *cols, uint32_t *rows)
{
	uint32_t	i;
	char		*line;
	char		**values;

	line = get_next_line(fd);
	*cols = ft_n_substr(line, ' ');
	while (*cols && line)
	{
		(*rows)++;
		i = 0;
		values = ft_split(line, ' ');
		while (values && *cols && ft_is_number(values[i]))
			i++;
		ft_free_single((void **) &line);
		ft_free_double((void ***) &values, -1);
		if (i != *cols)
			*cols = 0;
		else
			line = get_next_line(fd);
	}
}

float	parse_number(char *str_nbr)
{
	char	*hexa_starting;
	float	dec_number;
	float	hex_number;
	int32_t	len_hex_number;

	if (! ft_strnstr(str_nbr, "0x", ft_strlen(str_nbr)))
		return (ft_atof(str_nbr));
	else
	{
		hexa_starting = ft_strnstr(str_nbr, "0x", ft_strlen(str_nbr)) + 2;
		if (! ft_strchr(str_nbr, '.') && ! ft_strchr(str_nbr, ','))
			return (ft_xatof(hexa_starting));
		else
		{
			str_nbr[hexa_starting - str_nbr - 3] = '\0';
			dec_number = ft_atof(str_nbr);
			hex_number = ft_xatof(hexa_starting);
			len_hex_number = ft_nbrlen((uint32_t) hex_number, 10);
			return (dec_number + hex_number * ft_pow(10, len_hex_number * -1));
		}
	}
}

point2d_t	round_coor(point2d_t point)
{
	return ((point2d_t){ft_round_to_int(point.x), ft_round_to_int(point.y)});
}

float	distance(point2d_t p1, point2d_t p2)
{
	point2d_t	result;

	result.x = p2.x - p1.x;
	result.y = p2.y - p1.y;
	return (sqrt(ft_pow(result.x, 2) + ft_pow(result.y, 2)));
}
