/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:26:35 by faru          #+#    #+#                 */
/*   Updated: 2023/03/29 03:14:10 by fra           ########   odam.nl         */
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
}	point2d_t;

// entity that represents a point in a 3D-coordinates system
// @param x -> x coordinate
// @param y -> y coordinate
// @param z -> z coordinate
typedef struct point3d
{
	float	x;
	float	y;
	float	z;
}	point3d_t;

// map structure that is displayed on the screen
// @param map2d		-> array of 2D-elements (2d-map)
// @param map3d		-> array of 3D-elements (3d-map)
// @param cols		-> number of columns parsed from .fdf file
// @param rows		-> number of rows parsed from .fdf file
// @param grid_perc	-> size of graph relative to the image that contains it
// @param hor_pix	-> number of horizontal pixels
// @param ver_pix	-> number of veritical pixels
// @param win		-> (mlx object) window object
// @param img		-> (mlx object) imagine on which the 2d-map will be drawn
// @param grid_perc	-> size of image relative to the window that contains it
typedef struct map
{
	point2d_t		*map_2d;
	point3d_t		*map_3d;
	uint32_t		cols;
	uint32_t		rows;
	float			grid_perc;
	uint32_t		hor_pix;
	uint32_t		ver_pix;
	mlx_t			*win;
	mlx_image_t		*img;
	float			img_perc;
}	map_t;

// initialize the member map->win (type mlx_t) if it has success, creates
// the hooks (close, resize, press ESC, press WASD), draws the map
// @param map			-> container struct that hosts the mlx_t instance
// @param image_perc	-> size of the image realatively to the window
//
// return void
void		start_app(map_t	*map, float image_perc);

// close the app and terminates the program successfully
// @param param	-> instance of the container to clean
//
// return void
void		close_app(void *param);

void		set_image_in_win(map_t *map, int32_t w, int32_t h, int32_t bk_color);

void		draw_grid(map_t *map);

void		draw_line(map_t *map, point2d_t str, point2d_t end);

void		draw_pixel(map_t *map, point2d_t point);

point2d_t	find_focus(map_t *map);

point2d_t	find_min_map(map_t *map);

float		find_edge(map_t *map);

float		find_alpha(map_t *map, int32_t radius, point2d_t cursor_pos);

void		esc_hook(void *param);

void		resize_hook(int32_t width, int32_t height, void *param);

void		rotate_hook(mouse_key_t b, action_t a, modifier_key_t k, void *p);

void		translate_hook(mlx_key_data_t keydata, void *param);

void		rotate_map(map_t *map, char type, float rad);

void		shift_map(map_t *map, float plus_x, float plus_y);

void		resize_map(map_t *map, float amount);

map_t		*create_map(uint32_t cols, uint32_t rows, float perc);

void		free_map(map_t **map);

void		fill_map(int32_t fd, map_t *map);

void		render_map(map_t *map);

void		project_map(map_t *map);

point3d_t	iso_project(point3d_t p);

point3d_t	rotate_x(point3d_t p, float rad);

point3d_t	rotate_y(point3d_t p, float rad);

point3d_t	rotate_z(point3d_t p, float rad);

bool		check_input(int argc, char **argv, uint32_t *cols, uint32_t *rows);

void		parse_file(int32_t fd, uint32_t *cols, uint32_t *rows);

float		parse_n(char *number);

point2d_t	round_coor(point2d_t point);

float		distance(point2d_t p1, point2d_t p2);

#endif
