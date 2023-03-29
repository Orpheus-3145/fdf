/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 00:23:50 by fra           #+#    #+#                 */
/*   Updated: 2023/03/29 03:14:10 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int argc, char **argv)
{
	map_t		*map;
	int32_t		fd;
	uint32_t	cols;
	uint32_t	rows;

	if (! check_input(argc, argv, &cols, &rows))
		ft_raise_error("(fdf) Invalid input", 1);
	map = create_map(cols, rows, 0.8);
	fd = open(argv[1], O_RDONLY);
	fill_map(fd, map);
	close(fd);
	if (! map)
		ft_raise_error("(fdf) Memory error", 1);
	start_app(map, 0.8);
	if (! map)
		ft_raise_error("(fdf) Error in MLX42", 1);
	else
	{
		mlx_loop(map->win);
		free_map(&map);
	}
	return (EXIT_SUCCESS);
}
