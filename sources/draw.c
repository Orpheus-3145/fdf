/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 04:15:02 by fra           #+#    #+#                 */
/*   Updated: 2023/03/20 15:04:22 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_map *map)
{
	t_point2d	start;
	t_point2d	end;
	uint32_t	col;
	uint32_t	row;

	col = 0;
	row = 0;
	while (row < map->rows)
	{
		start = round_coor((map->map_2d)[row * map->cols + col]);
		if (row < map->rows - 1)
		{
			end = round_coor((map->map_2d)[(row + 1) * map->cols + col]);
			draw_line(map, start, end);
		}
		if (col < map->cols - 1)
		{
			end = round_coor((map->map_2d)[row * map->cols + col + 1]);
			draw_line(map, start, end);
		}
		col++;
		row += (col == map->cols);
		col *= (col != map->cols);
	}
}

void	draw_line(t_map *map, t_point2d start, t_point2d end)
{
	t_point2d	diff;
	t_point2d	sum;
	float		error;
	float		e2;

	diff = (t_point2d){ft_mod(end.x - start.x), ft_mod(end.y - start.y) * -1};
	sum = (t_point2d){1 - 2 * (start.x >= end.x), 1 - 2 * (start.y >= end.y)};
	error = diff.x + diff.y;
	while ((start.x != end.x) || (start.y != end.y))
	{
		draw_pixel(map, start);
		e2 = 2 * error;
		if ((e2 >= diff.y) || (e2 <= diff.x))
		{
			if ((start.x == end.x) && (start.y == end.y))
				break ;
			error += diff.y * (e2 >= diff.y);
			start.x += sum.x * (e2 >= diff.y);
			error += diff.x * (e2 <= diff.x);
			start.y += sum.y * (e2 <= diff.x);
		}
	}
}

void	draw_pixel(t_map *map, t_point2d point)
{
	while (point.x < 0)
		point.x += map->hor_pix;
	while (point.y < 0)
		point.y += map->ver_pix;
	while (point.x > map->hor_pix)
		point.x -= map->hor_pix;
	while (point.y > map->ver_pix)
		point.y -= map->ver_pix;
	mlx_put_pixel(map->img, (uint32_t) point.x, (uint32_t) point.y, RGBA_GRID);
}
