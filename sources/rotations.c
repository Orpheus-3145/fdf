/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 14:40:46 by faru          #+#    #+#                 */
/*   Updated: 2023/03/28 20:08:54 by fra           ########   odam.nl         */
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

t_point3d	rotate_x(t_point3d old_point, float rad)
{
	t_point3d rotated;

	rotated.x = old_point.x;
	rotated.y = old_point.y * cos(rad) - old_point.z * sin(rad);
	rotated.z = old_point.y * sin(rad) + old_point.z * cos(rad);
	return (rotated);
}

t_point3d	rotate_y(t_point3d old_point, float rad)
{
	t_point3d rotated;

	rotated.x = old_point.x * cos(rad) + old_point.z * sin(rad);
	rotated.y = old_point.y;
	rotated.z = -1 * old_point.x * sin(rad) + old_point.z * cos(rad);
	return (rotated);
}

t_point3d	rotate_z(t_point3d old_point, float rad)
{
	t_point3d rotated;

	rotated.x = old_point.x * cos(rad) - old_point.y * sin(rad);
	rotated.y = old_point.x * sin(rad) + old_point.y * cos(rad);
	rotated.z = old_point.z;
	return (rotated);
}
