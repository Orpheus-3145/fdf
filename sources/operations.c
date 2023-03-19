/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 14:40:46 by faru          #+#    #+#                 */
/*   Updated: 2023/03/17 17:59:44 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

point3d_t	iso_project(point3d_t p)
{
	point3d_t	tmp1;
	point3d_t	tmp2;

	tmp1 = rotate_z(p, M_PI_4 * -1);
	tmp2 = rotate_x(tmp1, (float) M_PI / 3);
	return (tmp2);
}

point3d_t	rotate_x(point3d_t p, float rad)
{
	float	x;
	float	z;
	float	y;

	x = p.x;
	y = p.y * cos(rad) - p.z * sin(rad);
	z = p.y * sin(rad) + p.z * cos(rad);
	return ((point3d_t){x, y, z});
}

point3d_t	rotate_y(point3d_t p, float rad)
{
	float	x;
	float	y;
	float	z;

	x = p.x * cos(rad) + p.z * sin(rad);
	y = p.y;
	z = -1 * p.x * sin(rad) + p.z * cos(rad);
	return ((point3d_t){x, y, z});
}

point3d_t	rotate_z(point3d_t p, float rad)
{
	float	x;
	float	y;
	float	z;

	x = p.x * cos(rad) - p.y * sin(rad);
	y = p.x * sin(rad) + p.y * cos(rad);
	z = p.z;
	return ((point3d_t){x, y, z});
}
