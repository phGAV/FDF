/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 01:22:55 by diona             #+#    #+#             */
/*   Updated: 2020/07/25 18:53:21 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *p, double alpha)
{
	int	y;
	int	z;

	y = p->y;
	z = p->z;
	p->y = y * cos(alpha) + z * sin(alpha);
	p->z = -y * sin(alpha) + z * cos(alpha);
}

static void	rotate_y(t_point *p, double alpha)
{
	int	x;
	int	z;

	x = p->x;
	z = p->z;
	p->x = x * cos(alpha) + z * sin(alpha);
	p->z = -x * sin(alpha) + z * cos(alpha);
}

static void	rotate_z(t_point *p, double alpha)
{
	int	y;
	int	x;

	y = p->y;
	x = p->x;
	p->x = x * cos(alpha) - y * sin(alpha);
	p->y = x * sin(alpha) + y * cos(alpha);
}

static void	iso(t_point *p)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(0.523599);
	p->y = -p->z + (x + y) * sin(0.523599);
}

t_point		projection(t_point p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->ratio_z;
	p.x -= fdf->map->width * fdf->camera->zoom / 2;
	p.y -= fdf->map->height * fdf->camera->zoom / 2;
	rotate_x(&p, fdf->camera->angle_x);
	rotate_y(&p, fdf->camera->angle_y);
	rotate_z(&p, fdf->camera->angle_z);
	if (fdf->camera->projection == ISO)
		iso(&p);
	p.x += WIN_WIDTH / 2 + fdf->camera->offset_x;
	p.y += WIN_HEIGHT / 2 + fdf->camera->offset_y;
	return (p);
}
