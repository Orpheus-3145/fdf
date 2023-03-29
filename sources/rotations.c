/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 14:40:46 by faru          #+#    #+#                 */
/*   Updated: 2023/03/30 01:29:01 by fra           ########   odam.nl         */
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

point3d_t	rotate_x(point3d_t old_point, float rad)
{
	point3d_t	rotated;

	rotated.x = old_point.x;
	rotated.y = old_point.y * cos(rad) - old_point.z * sin(rad);
	rotated.z = old_point.y * sin(rad) + old_point.z * cos(rad);
	return (rotated);
}

point3d_t	rotate_y(point3d_t old_point, float rad)
{
	point3d_t	rotated;

	rotated.x = old_point.x * cos(rad) + old_point.z * sin(rad);
	rotated.y = old_point.y;
	rotated.z = -1 * old_point.x * sin(rad) + old_point.z * cos(rad);
	return (rotated);
}

point3d_t	rotate_z(point3d_t old_point, float rad)
{
	point3d_t	rotated;

	rotated.x = old_point.x * cos(rad) - old_point.y * sin(rad);
	rotated.y = old_point.x * sin(rad) + old_point.y * cos(rad);
	rotated.z = old_point.z;
	return (rotated);
}
