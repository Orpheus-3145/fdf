/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 16:08:16 by faru          #+#    #+#                 */
/*   Updated: 2023/04/18 18:55:02 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

map_t	*create_map(uint32_t cols, uint32_t rows, float grid_perc)
{
	map_t	*map;

	map = malloc(sizeof(map_t));
	if (! map)
		ft_raise_error("(fdf) Memory error", 1);
	map->grid_perc = grid_perc;
	map->hor_pix = WIDTH * map->grid_perc;
	map->ver_pix = HEIGHT * map->grid_perc;
	map->cols = cols;
	map->rows = rows;
	map->map_2d = malloc(cols * rows * sizeof(point2d_t));
	map->map_3d = malloc(cols * rows * sizeof(point3d_t));
	if (! map->map_2d || ! map->map_3d)
	{
		free_map(&map);
		ft_raise_error("(fdf) Memory error", 1);
	}
	map->win = NULL;
	map->img = NULL;
	map->img_perc = 1;
	return (map);
}

void	free_map(map_t **map)
{
	if (*map)
	{
		if ((*map)->win)
			mlx_terminate((*map)->win);
		ft_free_single((void **) &((*map)->map_2d));
		ft_free_single((void **) &((*map)->map_3d));
		ft_free_single((void **) map);
	}
}

void	fill_map(int32_t fd, map_t *map)
{
	int32_t	i;
	int32_t	j;
	int32_t	tot;
	char	*row;
	char	**cols;

	row = get_next_line(fd);
	if (! row)
		free_map(&map);
	i = 0;
	tot = 0;
	while (map && row)
	{
		j = 0;
		cols = ft_split(row, ' ');
		if (! cols)
			free_map(&map);
		while (map && cols && cols[j++])
			(map->map_3d)[tot++] = (point3d_t){j - 1, i, parse_number(cols[j - 1])};
		ft_free_double((void ***) &cols, -1);
		ft_free_single((void **) &row);
		row = get_next_line(fd);
		i++;
	}
}

void	project_map(map_t *map)
{
	uint32_t	i;

	i = 0;
	while (i < (map->cols * map->rows))
	{
		(map->map_3d)[i] = iso_project((map->map_3d)[i]);
		i++;
	}
}

void	render_map(map_t *map)
{
	float		edge;
	uint32_t	i;
	point2d_t	centre;
	point2d_t	focus;
	point2d_t	min;

	i = 0;
	while (i < (map->cols * map->rows))
	{
		(map->map_2d)[i].x = (map->map_3d)[i].x;
		(map->map_2d)[i].y = (map->map_3d)[i].y;
		i++;
	}
	edge = find_edge(map);
	resize_map(map, edge * map->grid_perc);
	focus = find_focus(map);
	min = find_min_map(map);
	centre.x = (map->hor_pix - focus.x) / 2 - min.x;
	centre.y = (map->ver_pix - focus.y) / 2 - min.y;
	shift_map(map, centre.x, centre.y);
	draw_grid(map);
}
