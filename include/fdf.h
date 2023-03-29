/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:26:35 by faru          #+#    #+#                 */
/*   Updated: 2023/03/30 01:24:27 by fra           ########   odam.nl         */
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
// @param map2d		-> array of 2D-elements (2D-map)
// @param map3d		-> array of 3D-elements (3d-map)
// @param cols		-> number of columns parsed from .fdf file
// @param rows		-> number of rows parsed from .fdf file
// @param grid_perc	-> size of graph relative to the image that contains it
// @param hor_pix	-> number of horizontal pixels
// @param ver_pix	-> number of veritical pixels
// @param win		-> (mlx object) window object
// @param img		-> (mlx object) imagine on which the 2D-map will be drawn
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

// when the window (mlx_t instance) is created or when it is resized, it
// centres the image and it sets the color
// @param map	-> container struct that hosts the mlx_t instance
// @param w		-> width of the window
// @param h		-> height of the window
// @param color	-> color of the image (i.e. the background)
//
// return void
void		set_image_in_win(map_t *map, int32_t w, int32_t h, int32_t bk_col);

// draws the lines from every 2Dpoint: every (x,y) in conjuncted with the
// point (x+1,y) and (x, y+1)
// @param map	-> container struct that stores the 2D map
//
// return void
void		draw_grid(map_t *map);

// draws a single line from start to end (Bresenham's Algorithm)
// @param map	-> container struct that stores the 2D map
// @param start	-> starting point
// @param end	-> ending point
//
// return void
void		draw_line(map_t *map, point2d_t start, point2d_t end);

// draws the single pixel/point
// @param map	-> container struct that stores the 2D map
// @param start	-> point to represent
//
// return void
void		draw_pixel(map_t *map, point2d_t point);

// finds the focus, i.e. the centre of the 2D map
// @param map		-> container struct that stores the 2D map
//
// return point2d_t	-> focus point
point2d_t	find_focus(map_t *map);

// finds the minimum x and y 2D-coordinates
// @param map		-> container struct that stores the 2D map
//
// return point2d_t	-> min x, y
point2d_t	find_min_map(map_t *map);

// finds the biggest delta (i.e. the maximum value of x or y) and divides
// the meximum amount of point on x or y axis with that value, the edge
// represent the longest line possibile from a point x1 to x2.
// Every point of the 2D map is going to be multiplied by the edge
// @param map	-> container struct that stores the 2D map
//
// return float	-> the edge
float		find_edge(map_t *map);

// regarding rotations, finds the corner that represent the amount of space
// walked by the cursor from point A to point B (drag and drop)
// the graph will be rotated by this corner
// @param map			-> container struct that stores the 2D map
// @param radius		-> amount of pixels walked by the cursor
// @param cursor_pos	-> current position of the cursor
//
// return float	-> the alpha (in radiants!)
float		find_alpha(map_t *map, int32_t radius, point2d_t cursor_pos);

// function to be called when the key ESC is pressed: closes the app and
// deallocates the memory
// @param param	-> the functions expects a map_t* type
//
// return void
void		esc_hook(void *param);

// function to be called when the the window is resized: adapts the graph
// to the ne width and heigth value
// @param width		-> the new width of the window
// @param height	-> the new height of the window
// @param param		-> the functions expects a map_t* type
//
// return void
void		resize_hook(int32_t width, int32_t height, void *param);

// function to be called when the the graph is rotated (drag and drop action)
// @param n	-> mouse button pressed
// @param a	-> type of action (press, release, ...)
// @param k	-> other key pressed
// @param p	-> the functions expects a map_t* type
//
// return void
void		rotate_hook(mouse_key_t b, action_t a, modifier_key_t k, void *p);

// function to be called when the W, A, S or D key is pressed: moves
// the graph up, left, down, right (respectively) by 10 pixels
// @param keydata	-> key pressed
// @param param		-> the functions expects a map_t* type
//
// return void
void		translate_hook(mlx_key_data_t keydata, void *param);

// rotates the 3D map by a corner rad on type axis
// @param map	-> container struct that stores the 3D map
// @param type	-> direction: x, y or z
// @param rad	-> amount of radiants to rotate the graph
//
// return void
void		rotate_map(map_t *map, char type, float rad);

// moves the 2D map by plus_x pixels on x axis and plus_y pixels
// on y axis
// @param map		-> container struct that stores the 2D map
// @param plus_x	-> amount of horizontal pixels to move
// @param plus_y	-> amount of vertical pixels to move
// @param rad	-> amount of radiants to rotate the graph
//
// return void
void		shift_map(map_t *map, float plus_x, float plus_y);

// increases or decreases the size of the graph by amount on both
// axis
// @param map		-> container struct that stores the 2D map
// @param amount	-> times to multiply x and y coordinates
//
// return void
void		resize_map(map_t *map, float amount);

// creates a map_t instance from the number of rows and columns
// of a map
// @param cols		-> number of columns of the map
// @param rows		-> number of rows of the map
// @param perc		-> relative size of the graph inside the image 
//						(i.e. perc = 1  => the graph has the size of the bk)
//
// @return map_t	-> container instance
map_t		*create_map(uint32_t cols, uint32_t rows, float perc);

// deallocates the memory of the container
// NB: the function mlx_terminate() has leaks!
// @param map		-> container struct to free
//
// @return void
void		free_map(map_t **map);

// reads the file pointed by fd and stores every
// (x,y,z) point inside the 3D map
// @param fd	-> file descriptr that represents a valid .fdf file to read
// @param map	-> container struct that stores the 3D map
//
// @return void
void		fill_map(int32_t fd, map_t *map);

// renders the 3D map into a 2D map: first it takes only the (x,y) coors,
// then it enlarges the map, it shifts the graph so that it starts in (0,0)
// and finally it draws the lines
// @param map	-> container struct that stores the maps
//
// @return void
void		render_map(map_t *map);

// applies the isometric projection to every point of the 3D
// @param map	-> container struct that stores the 3D map
//
// @return void
void		project_map(map_t *map);

// applies the isometric projection to a single point, i.e. -PI/4 (-45°) on z
// PI/3 (60°) on x
// @param p				-> point to rotate
//
// @return point3d_t	-> point rotated
point3d_t	iso_project(point3d_t p);

// rotates the point p by rad on x axis
// @param p				-> point to rotate
//
// @return point3d_t	-> point rotated
point3d_t	rotate_x(point3d_t p, float rad);

// rotates the point p by rad on y axis
// @param p				-> point to rotate
//
// @return point3d_t	-> point rotated
point3d_t	rotate_y(point3d_t p, float rad);

// rotates the point p by rad on z axis
// @param p				-> point to rotate
//
// @return point3d_t	-> point rotated
point3d_t	rotate_z(point3d_t p, float rad);

// checks the given file is valid, if so it saves the number of columns
// and rows in cols and rows (done by)
// @param argc	-> argc variable
// @param argv	-> argv variable
// @param cols		-> number of columns of the map
// @param rows		-> number of rows of the map
//
// @return false/true (cols and rows set to 0)
bool		check_input(int argc, char **argv, uint32_t *cols, uint32_t *rows);

// reads line by line the file and checks if every number is valid, stores
// the amount or columns and rows inside the two uint32_t pointers 
// @param fd	-> file descriptor of .fdf. file
// @param cols	-> 
// @param fd	-> file descriptor of .fdf. file
void		parse_file(int32_t fd, uint32_t *cols, uint32_t *rows);

// converts the number from string to float (decimal or hexadecimal or mix)
// @param number	-> string to convert
//
// @return float	-> number converted
float		parse_number(char *number);

// rounds the decimal part of the x any y coordinates
// @param point			-> (x,y) point to convert
//
// @return point2d-t	-> (x,y) point converted
point2d_t	round_coor(point2d_t point);

// Euclidean distance of two points
// @param p1	-> first point
// @param p2	-> second point
//
// @return float	-> distance (ofc >= 0)
float		distance(point2d_t p1, point2d_t p2);

#endif
