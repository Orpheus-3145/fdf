/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/18 04:38:34 by fra           #+#    #+#                 */
/*   Updated: 2023/03/19 03:43:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	esc_hook(void *param)
{
	map_t	*map;

	map = (map_t *) param;
	if (mlx_is_key_down(map->win, MLX_KEY_ESCAPE))
		close_app(map);
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	map_t	*map;

	map = (map_t *) param;
	map->hor_pix = width;
	map->ver_pix = height;
	set_image_in_win(map, width, height, RGBA_BK);
	render_map(map, 0.8, RGBA_FDF);
}

void	rotate_hook(mouse_key_t b, action_t act, modifier_key_t k, void *param)
{
	map_t			*p;
	static int32_t	c_x;
	static int32_t	c_y;
	int32_t			n_x;
	int32_t			n_y;

	p = (map_t *) param;
	k += 1;
	if (b != MLX_MOUSE_BUTTON_LEFT)
		return ;
	else if (act == MLX_PRESS)
		mlx_get_mouse_pos(p->win, &c_x, &c_y);
	else if (act == MLX_RELEASE)
	{
		mlx_get_mouse_pos(p->win, &n_x, &n_y);
		ft_memset(p->img->pixels, RGBA_BK, p->hor_pix * p->ver_pix * BPP);
		if (ft_mod(n_x - c_x) > ft_mod(n_y - c_y))
			rotate_map(p, 'x', find_alpha(p, n_x - c_x, (point2d_t){n_x, n_y}));
		else
			rotate_map(p, 'y', find_alpha(p, n_y - c_y, (point2d_t){n_x, n_y}));
		render_map(p, 0.8, RGBA_FDF);
		c_x = 0;
		c_y = 0;
	}
}

void	translate_hook(mlx_key_data_t keydata, void *param)
{
	map_t	*map;
	int32_t	amount;

	if (keydata.action == MLX_RELEASE
		&& ((keydata.key == MLX_KEY_W)
			|| (keydata.key == MLX_KEY_A)
			|| (keydata.key == MLX_KEY_W)
			|| (keydata.key == MLX_KEY_S)))
	{
		map = (map_t *) param;
		if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_A))
			amount = -10;
		else
			amount = 10;
		if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_S))
			shift_map(map, 0, amount);
		else
			shift_map(map, amount, 0);
		ft_memset(map->img->pixels, RGBA_BK, map->hor_pix * map->ver_pix * BPP);
		draw_grid(map, RGBA_FDF);
	}
}
