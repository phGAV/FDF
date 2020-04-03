/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 01:22:55 by diona             #+#    #+#             */
/*   Updated: 2020/04/03 18:33:08 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*camera_init(t_map *map)
{
	t_camera	*camera;
	int			y_scale;
	int			x_scale;

	camera = ft_malloc(sizeof(t_camera));
	y_scale = WIN_HEIGHT / map->height / 2;
	x_scale = WIN_WIDTH / map->width / 2;
	camera->projection = ISO;
	camera->angle_x = 0;
	camera->angle_y = 0;
	camera->angle_z = 0;
	camera->ratio_z = 2;
	camera->zoom = y_scale > x_scale ? x_scale : y_scale;
	camera->offset_x = (WIN_WIDTH - map->width * camera->zoom) / 2;
	camera->offset_y = (WIN_HEIGHT - map->height * camera->zoom) / 2;
	return (camera);
}

t_point	*get_point(int x, int y, t_map *map)
{
	t_point	*p;

	p = (t_point *)ft_malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = map->vertex[y][x];
	p->color = p->z == map->max_z ? PINK : TURQUOISE;
	// p->color = p->z == map->min_z ? PINK : TURQUOISE;

	return (p);
}

void	rotate_x(t_point *p, double alpha)
{
	int	y;
	int	z;

	y = p->y;
	z = p->z;
	p->y = y * cos(alpha) - z * sin(alpha);
	p->z = y * sin(alpha) + z * cos(alpha);
}

void	rotate_y(t_point *p, double alpha)
{
	int	x;
	int	z;

	x = p->x;
	z = p->z;
	p->x = x * cos(alpha) + z * sin(alpha);
	p->z = -x * sin(alpha) + z * cos(alpha);
}

void	rotate_z(t_point *p, double alpha)
{
	int	y;
	int	x;

	y = p->y;
	x = p->x;
	p->x = x * cos(alpha) - y * sin(alpha);
	p->y = x * sin(alpha) + y * cos(alpha);
}

void	iso(t_point *p)
{
	// *x = (previous_x - previous_y) * cos(0.523599);
	// *y = -z + (previous_x + previous_y) * sin(0.523599);
	int	x;
	int	y;
	double a = 35.264;
	double b = 45;

	x = p->x;
	y = p->y;
	// p->x = (x - y) * cos(0.46365);
	// p->y = p->z + (x + y) * sin(0.46365);
	// p->y = p->z * sin(a) + (x + y) * cos(a * M_PI / 180) * cos(b * M_PI / 180);
	p->x = (x - y) * cos(0.523599);
	p->y = -p->z + (x + y) * sin(0.523599);
}

t_point	projection(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->camera->zoom;
	p->y *= fdf->camera->zoom;
	p->z *= fdf->camera->ratio_z;
	rotate_x(p, fdf->camera->angle_x);
	rotate_y(p, fdf->camera->angle_y);
	rotate_z(p, fdf->camera->angle_z);
	iso(p);
	p->x += fdf->camera->offset_x;
	p->y += fdf->camera->offset_y;
	return (*p);
}

void	draw_map(t_map *map, t_fdf *fdf)
{
	int	y;
	int	x;

	fdf->camera = camera_init(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((x + 1) < map->width)
				draw_line(projection(get_point(x, y, map), fdf),
						projection(get_point(x + 1, y, map), fdf), fdf);
			if ((y + 1) < map->height)
				draw_line(projection(get_point(x, y, map), fdf),
						projection(get_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
}
