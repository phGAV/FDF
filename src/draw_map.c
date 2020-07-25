/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:57:31 by diona             #+#    #+#             */
/*   Updated: 2020/07/10 01:14:02 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	get_point(int x, int y, t_map *map)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = ((int *)map->vertex->data)[y * map->width + x];
	p.color = find_vertex_color(map, map->max_z, map->min_z, p.z);
	return (p);
}

void			set_background(int *img_ptr, int color, size_t size)
{
	const int	*last_pixel = img_ptr + size;

	while (img_ptr <= last_pixel)
		*img_ptr++ = color;
}

void			draw_string(t_fdf *fdf, char *s)
{
	static int y;

	y += *s == ' ' ? 25 : 45;
	mlx_string_put(fdf->mlx, fdf->window, WIN_WIDTH + 25, y, WHITE, s);
}

void			draw_menu(t_fdf *fdf)
{
	set_background(fdf->menu_ptr, BG_MENU, MENU_WIDTH * WIN_HEIGHT);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu, WIN_WIDTH, 0);
	draw_string(fdf, "Move:");
	draw_string(fdf, "  Drag LMB");
	draw_string(fdf, "  Arrows");
	draw_string(fdf, "Rotate:");
	draw_string(fdf, "  Drag RMB");
	draw_string(fdf, "  X: 1/2");
	draw_string(fdf, "  Y: 3/4");
	draw_string(fdf, "  Z: 5/6");
	draw_string(fdf, "Zoom: Mouse scroll");
	draw_string(fdf, "Flatten: -/+");
	draw_string(fdf, "Projection: I/P");
	draw_string(fdf, "Change colors: C");
	draw_string(fdf, "Motion blur: M");
}

int				gallop_x(bool *next_exists, int x, int y, t_map *map)
{
	const int	*vertex = map->vertex->data;
	const int	z = vertex[y * map->width + x];

	if (z != vertex[y * map->width + x + 1])
		return (x + 1);
	while (x <= map->height && z != vertex[y * map->width + x])
		x++;
	if (x == map->height)
		*next_exists = false;
	return (x);
}

void			draw_map(t_fdf *fdf)
{
	int			y;
	int			x;
	bool		next_exists;
	t_point		start;
	t_point		end;

	set_background(fdf->img_ptr, fdf->map->bg_color, WIN_WIDTH * WIN_HEIGHT);
	y = 0;
	x = 0;
	next_exists = true;
	while (y <= fdf->map->height)
	{
		start = get_point(x, y, fdf->map);
		end = get_point(gallop_x(&next_exists, x, y, fdf->map), y, fdf->map);
		draw_line(projection(start, fdf), projection(end, fdf), fdf);
		x = end.x;
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}

void			draw_map0(t_fdf *fdf)
{
	int			y;
	int			x;

	set_background(fdf->img_ptr, fdf->map->bg_color, WIN_WIDTH * WIN_HEIGHT);
	// mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if ((x + 1) < fdf->map->width)
				draw_line(projection(get_point(x, y, fdf->map), fdf),
						projection(get_point(x + 1, y, fdf->map), fdf), fdf);
			if ((y + 1) < fdf->map->height)
				draw_line(projection(get_point(x, y, fdf->map), fdf),
						projection(get_point(x, y + 1, fdf->map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}
