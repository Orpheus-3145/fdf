/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 00:23:50 by fra           #+#    #+#                 */
/*   Updated: 2023/03/20 15:14:23 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int argc, char **argv)
{
	t_map		*map;
	int32_t		fd;
	uint32_t	width;
	uint32_t	height;

	if (! check_input(argc, argv, &width, &height))
		ft_raise_error("(fdf) Invalid input", 1);
	map = create_map(width, height);
	fd = open(argv[1], O_RDONLY);
	fill_map(fd, map);
	close(fd);
	if (! map)
		ft_raise_error("(fdf) Memory error", 1);
	start_app(map, 0.8, 0.8);
	if (! map)
		ft_raise_error("(fdf) Error in MLX42", 1);
	else
	{
		mlx_loop(map->win);
		free_map(&map);
	}
	return (EXIT_SUCCESS);
}
