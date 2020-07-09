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
	p.z = *(int *)vec_get(map->vertex, y * map->width + x);
	p.color = find_vertex_color(map->max_z, map->min_z, p.z);
	return (p);
}

void			set_background(t_fdf *fdf)
{
	ft_bzero(fdf->img_ptr, sizeof(int) * WIN_WIDTH * WIN_HEIGHT);
}

void			draw_map(t_fdf *fdf)
{
	int			y;
	int			x;

	set_background(fdf);
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
}
