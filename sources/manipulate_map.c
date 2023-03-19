/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manipulate_map.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 20:46:17 by fra           #+#    #+#                 */
/*   Updated: 2023/03/19 02:17:06 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map(map_t *map, char type, float alpha)
{
	uint32_t	i;

	i = 0;
	while (i < (map->cols * map->rows))
	{
		if (type == 'x')
			(map->map_3d)[i] = rotate_y((map->map_3d)[i], alpha);
		else if (type == 'y')
			(map->map_3d)[i] = rotate_x((map->map_3d)[i], alpha);
		else if (type == 'z')
			(map->map_3d)[i] = rotate_z((map->map_3d)[i], alpha);
		i++;
	}
}

void	shift_map(map_t *map, float plus_x, float plus_y)
{
	uint32_t	i;

	i = 0;
	while (i < (map->cols * map->rows))
	{
		(map->map_2d)[i].x += plus_x;
		(map->map_2d)[i].y += plus_y;
		i++;
	}
}

void	resize_map(map_t *map, float amount)
{
	uint32_t	i;

	i = 0;
	while (i < map->cols * map->rows)
	{
		(map->map_2d)[i].x *= amount;
		(map->map_2d)[i].y *= amount;
		i++;
	}
}
