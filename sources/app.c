/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:10:34 by fra           #+#    #+#                 */
/*   Updated: 2023/03/20 14:52:13 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_app(t_map	*map, float image_perc, float grid_perc)
{
	if (! map)
		return ;
	map->win = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (! map->win)
		free_map(&map);
	else
	{
		mlx_loop_hook(map->win, &esc_hook, map);
		mlx_close_hook(map->win, &close_app, map);
		mlx_resize_hook(map->win, &resize_hook, map);
		mlx_mouse_hook(map->win, &rotate_hook, map);
		mlx_key_hook(map->win, &translate_hook, map);
		set_image_in_win(map, WIDTH, HEIGHT, image_perc);
		if (! map->img)
			free_map(&map);
		else
		{
			project_map(map);
			render_map(map, grid_perc);
		}
	}
}

void	close_app(void *param)
{
	t_map	*map;

	if (param)
	{
		map = (t_map *) param;
		free_map(&map);
	}
	exit(EXIT_SUCCESS);
}

void	set_image_in_win(t_map *map, int32_t w, int32_t h, float perc)
{
	uint32_t	start_x;
	uint32_t	start_y;

	map->hor_pix = w * perc;
	map->ver_pix = h * perc;
	start_x = (w - map->hor_pix) / 2;
	start_y = (h - map->ver_pix) / 2;
	if (! map->img)
	{
		map->img = mlx_new_image(map->win, map->hor_pix, map->ver_pix);
		if (! map->img)
			return ;
		mlx_image_to_window(map->win, map->img, start_x, start_y);
	}
	else
	{
		map->img->instances[0].x = start_x;
		map->img->instances[0].y = start_y;
		mlx_resize_image(map->img, map->hor_pix, map->ver_pix);
	}
	ft_memset(map->img->pixels, RGBA_BK, map->hor_pix * map->ver_pix * BPP);
}
