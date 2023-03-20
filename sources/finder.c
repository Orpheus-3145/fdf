/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finder.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/17 02:18:49 by fra           #+#    #+#                 */
/*   Updated: 2023/03/20 14:55:26 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d	find_focus(t_map *map)
{
	t_point2d	max;
	t_point2d	min;
	uint32_t	i;

	i = 1;
	max = (map->map_2d)[0];
	min = (map->map_2d)[0];
	while (i < map->cols * map->rows)
	{
		if (max.x < (map->map_2d)[i].x)
			max.x = (map->map_2d)[i].x;
		if (max.y < (map->map_2d)[i].y)
			max.y = (map->map_2d)[i].y;
		if (min.x > (map->map_2d)[i].x)
			min.x = (map->map_2d)[i].x;
		if (min.y > (map->map_2d)[i].y)
			min.y = (map->map_2d)[i].y;
		i++;
	}
	return ((t_point2d){max.x - min.x, max.y - min.y});
}

t_point2d	find_min_map(t_map *map)
{
	t_point2d	min;
	uint32_t	i;

	i = 1;
	min = (map->map_2d)[0];
	while (i < (map->cols * map->rows))
	{
		if (min.x > (map->map_2d)[i].x)
			min.x = (map->map_2d)[i].x;
		if (min.y > (map->map_2d)[i].y)
			min.y = (map->map_2d)[i].y;
		i++;
	}
	return (min);
}

float	find_edge(t_map *map)
{
	float		edge;
	t_point2d	focus;

	focus = find_focus(map);
	if (focus.x > focus.y)
	{
		edge = (float) map->hor_pix / focus.x;
		if (edge * focus.y > map->ver_pix)
			edge = (float) map->ver_pix / focus.y;
	}
	else
	{
		edge = (float) map->ver_pix / focus.y;
		if (edge * focus.x > map->hor_pix)
			edge = (float) map->hor_pix / focus.x;
	}
	return (edge);
}

float	find_alpha(t_map *map, int32_t radius, t_point2d cursor_pos)
{
	bool	sign;
	float	d;
	float	alpha;

	sign = false;
	if (radius < 0)
	{
		sign = true;
		radius *= -1;
	}
	d = distance(find_focus(map), cursor_pos);
	alpha = ((float) radius / d);
	if (sign)
		alpha *= -1;
	return (alpha);
}
