/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 14:40:46 by faru          #+#    #+#                 */
/*   Updated: 2023/03/19 19:03:42 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3d	iso_project(t_point3d p)
{
	t_point3d	tmp1;
	t_point3d	tmp2;

	tmp1 = rotate_z(p, M_PI_4 * -1);
	tmp2 = rotate_x(tmp1, (float) M_PI / 3);
	return (tmp2);
}

t_point3d	rotate_x(t_point3d p, float rad)
{
	float	x;
	float	z;
	float	y;

	x = p.x;
	y = p.y * cos(rad) - p.z * sin(rad);
	z = p.y * sin(rad) + p.z * cos(rad);
	return ((t_point3d){x, y, z});
}

t_point3d	rotate_y(t_point3d p, float rad)
{
	float	x;
	float	y;
	float	z;

	x = p.x * cos(rad) + p.z * sin(rad);
	y = p.y;
	z = -1 * p.x * sin(rad) + p.z * cos(rad);
	return ((t_point3d){x, y, z});
}

t_point3d	rotate_z(t_point3d p, float rad)
{
	float	x;
	float	y;
	float	z;

	x = p.x * cos(rad) - p.y * sin(rad);
	y = p.x * sin(rad) + p.y * cos(rad);
	z = p.z;
	return ((t_point3d){x, y, z});
}
