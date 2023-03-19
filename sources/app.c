/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 18:10:34 by fra           #+#    #+#                 */
/*   Updated: 2023/03/19 03:44:45 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_app(map_t	*map)
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
		set_image_in_win(map, WIDTH, HEIGHT, RGBA_BK);
		if (! map->img)
			free_map(&map);
		else
		{
			project_map(map);
			render_map(map, 0.8, RGBA_FDF);
		}
	}
}

void	close_app(void *param)
{
	map_t	*map;

	if (param)
	{
		map = (map_t *) param;
		free_map(&map);
	}
	exit(EXIT_SUCCESS);
}

void	set_image_in_win(map_t *map, int32_t w, int32_t h, int32_t bk_color)
{
	uint32_t	start_x;
	uint32_t	start_y;

	map->hor_pix = w * 0.8;
	map->ver_pix = h * 0.8;
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
	ft_memset(map->img->pixels, bk_color, map->hor_pix * map->ver_pix * BPP);
}
