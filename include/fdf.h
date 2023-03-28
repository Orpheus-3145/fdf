/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:26:35 by faru          #+#    #+#                 */
/*   Updated: 2023/03/28 22:09:55 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>			// malloc(), free()
# include <math.h>				// sin(), cos(), M_PI, ...
# include "MLX42/MLX42.h"		// graphic library
# include "libft.h"				// libft library
# ifdef __APPLE__				
#  define WIDTH 2400			// horizonal pixels on Mac
#  define HEIGHT 1350			// vertical pixels on Mac
# elif defined(__linux__)	
#  define WIDTH 800				// horizonal pixels on Linux
#  define HEIGHT 450			// vertical pixels on Linux
# endif
# define RGBA_BK 0xFFFFFFFF		// color of background of window (white)
# define RGBA_GRID 0x00FF00FF	// color of grid (green)
# define BPP 4					// bytes of every pixel (int type)

// entity that represents a point in a 2D-coordinates system
// @param x -> x coordinate
// @param y -> y coordinate
typedef struct point2d
{
	float	x;
	float	y;
}	t_point2d;

// entity that represents a point in a 3D-coordinates system
// @param x -> x coordinate
// @param y -> y coordinate
// @param z -> z coordinate
typedef struct point3d
{
	float	x;
	float	y;
	float	z;
}	t_point3d;

// map structure that is displayed on the screen
// @param map2d		-> array of 2D-elements (2d-map)
// @param map3d		-> array of 3D-elements (3d-map)
// @param cols		-> number of columns parsed from .fdf file
// @param rows		-> number of rows parsed from .fdf file
// @param hor_pix	-> number of horizontal pixels
// @param ver_pix	-> number of veritical pixels
// #param win		-> (mlx object) window object
// @param img		-> (mlx object) imagine on which the 2d-map will be represented
typedef struct map
{
	t_point2d		*map_2d;
	t_point3d		*map_3d;
	uint32_t		cols;
	uint32_t		rows;
	uint32_t		hor_pix;
	uint32_t		ver_pix;
	mlx_t			*win;
	mlx_image_t		*img;
}	t_map;

void		start_app(t_map	*map, float image_perc, float grid_perc);

void		close_app(void *param);

void		set_image_in_win(t_map *map, int32_t w, int32_t h, float perc);

void		draw_grid(t_map *map);

void		draw_line(t_map *map, t_point2d str, t_point2d end);

void		draw_pixel(t_map *map, t_point2d point);

t_point2d	find_focus(t_map *map);

t_point2d	find_min_map(t_map *map);

float		find_edge(t_map *map);

float		find_alpha(t_map *map, int32_t radius, t_point2d cursor_pos);

void		esc_hook(void *param);

void		resize_hook(int32_t width, int32_t height, void *param);

void		rotate_hook(mouse_key_t b, action_t a, modifier_key_t k, void *p);

void		translate_hook(mlx_key_data_t keydata, void *param);

void		rotate_map(t_map *map, char type, float rad);

void		shift_map(t_map *map, float plus_x, float plus_y);

void		resize_map(t_map *map, float amount);

t_map		*create_map(uint32_t cols, uint32_t rows);

void		free_map(t_map **map);

void		fill_map(int32_t fd, t_map *map);

void		render_map(t_map *map, float perc);

void		project_map(t_map *map);

t_point3d	iso_project(t_point3d p);

t_point3d	rotate_x(t_point3d p, float rad);

t_point3d	rotate_y(t_point3d p, float rad);

t_point3d	rotate_z(t_point3d p, float rad);

bool		check_input(int argc, char **argv, uint32_t *cols, uint32_t *rows);

void		parse_file(int32_t fd, uint32_t *cols, uint32_t *rows);

float		parse_n(char *number);

t_point2d	round_coor(t_point2d point);

float		distance(t_point2d p1, t_point2d p2);

#endif
