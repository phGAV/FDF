/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 01:22:55 by diona             #+#    #+#             */
/*   Updated: 2020/04/08 23:56:06 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*get_point(int x, int y, t_map *map)
{
	t_point	*p;

	p = (t_point *)ft_malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = map->vertex[y][x];
	p->color = find_vertex_color(map->max_z, map->min_z, p->z);

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
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(0.523599);
	p->y = -p->z + (x + y) * sin(0.523599);
}

t_point	projection(t_point *p, t_fdf *fdf, t_map *map)
{
	p->x *= fdf->camera->zoom;
	p->y *= fdf->camera->zoom;
	p->z *= fdf->camera->ratio_z;
	p->x -= map->width * fdf->camera->zoom / 2;
	p->y -= map->height * fdf->camera->zoom / 2;
	rotate_x(p, fdf->camera->angle_x);
	rotate_y(p, fdf->camera->angle_y);
	rotate_z(p, fdf->camera->angle_z);
	if (fdf->camera->projection == ISO)
		iso(p);
	p->x += WIN_WIDTH / 2 + fdf->camera->offset_x;
	p->y += WIN_HEIGHT / 2 + fdf->camera->offset_y;
	return (*p);
}

void	draw_map(t_fdf *fdf)
{
	int		y;
	int		x;
	t_map	*map;

	set_background(fdf);
	// mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->back, 0, 0);
	map = fdf->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((x + 1) < map->width)
				draw_line(projection(get_point(x, y, map), fdf, map),
						projection(get_point(x + 1, y, map), fdf, map), fdf);
			if ((y + 1) < map->height)
				draw_line(projection(get_point(x, y, map), fdf, map),
						projection(get_point(x, y + 1, map), fdf, map), fdf);
			x++;
		}
		y++;
	}
}
