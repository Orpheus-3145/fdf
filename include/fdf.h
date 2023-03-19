/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:26:35 by faru          #+#    #+#                 */
/*   Updated: 2023/03/19 03:36:55 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# ifdef __APPLE__
#  define WIDTH 2400
#  define HEIGHT 1350
# elif defined(__linux__)
#  define WIDTH 800
#  define HEIGHT 450
# endif
# define RGBA_BK 0x00000000
# define RGBA_FDF 0x00FF00FF
# define BPP sizeof(int32_t)

typedef struct point2d
{
	float	x;
	float	y;
}   point2d_t;

typedef struct point3d
{
	float x;
	float y;
	float z;
}   point3d_t;

typedef struct  map
{
	point2d_t		*map_2d;
	point3d_t		*map_3d;
	uint32_t		cols;
	uint32_t		rows;
	uint32_t		hor_pix;
	uint32_t		ver_pix;
	mlx_t			*win;
	mlx_image_t		*img;
}	map_t;


void    	start_app(map_t	*map);

void		close_app(void *param);

void		set_image_in_win(map_t *map, int32_t width, int32_t height, int32_t bk_color);


void 		draw_grid(map_t *map, int32_t color);

void 		draw_line(map_t *map, point2d_t start, point2d_t end, int32_t color);

void		draw_pixel(map_t *map, point2d_t point, int32_t color);


point2d_t	find_focus(map_t *map);

point2d_t	find_min_map(map_t *map);

float		find_edge(map_t *map);

float 		find_alpha(map_t *map, int32_t radius, point2d_t cursor_pos);


void		esc_hook(void *param);

void		resize_hook(int32_t width, int32_t height, void* param);

void		rotate_hook(mouse_key_t btn, action_t act, modifier_key_t key, void *param);

void		translate_hook(mlx_key_data_t keydata, void* param);


void		rotate_map(map_t *map, char type, float rad);

void		shift_map(map_t *map, float plus_x, float plus_y);

void		resize_map(map_t *map, float perc);


map_t*		create_map(uint32_t cols, uint32_t rows);

void		free_map(map_t **map);

void		fill_map(int32_t fd, map_t *map);

void		render_map(map_t *map, float perc, int32_t color);

void		project_map(map_t *map);


point3d_t   iso_project(point3d_t p);

point3d_t   rotate_x(point3d_t p, float rad);

point3d_t   rotate_y(point3d_t p, float rad);

point3d_t   rotate_z(point3d_t p, float rad);


bool		check_input(int argc, char **argv, uint32_t *cols, uint32_t *rows);

void		parse_file(int32_t fd, uint32_t *cols, uint32_t *rows);

float		parse_number(char *number);

point2d_t	round_coor(point2d_t point);

float		distance(point2d_t p1, point2d_t p2);

bool		wasd_released(mlx_key_data_t keydata);

#endif