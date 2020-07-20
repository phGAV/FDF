/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:21:21 by diona             #+#    #+#             */
/*   Updated: 2020/07/20 21:08:08 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		fdf->img_ptr[y * WIN_WIDTH + x] =
			mlx_get_color_value(fdf->mlx, color);
}

static void		straight_line(t_point start, t_point end, t_fdf *fdf)
{
	t_point		current;
	int			delta;

	delta = 1;
	current = start;
	if (start.x > end.x || start.y > end.y)
		delta *= -1;
	while (current.y != end.y || current.x != end.x)
	{
		if (start.x == end.x)
			current.y += delta;
		else
			current.x += delta;
		current.color = find_color(&current, &start, &end);
		put_pixel(fdf, current.x, current.y, current.color);
	}
}

static void		draw_along_y(t_point start, t_point end, t_fdf *fdf,
		double delta_err)
{
	t_point		current;
	double		x;

	current = start;
	x = start.x;
	if (start.x > end.x)
		delta_err = -delta_err;
	while (current.y < end.y)
	{
		current.color = find_color(&current, &start, &end);
		put_pixel(fdf, (int)floor(x), current.y,
			get_opacity(current.color, 1 - (x - floor(x))));
		put_pixel(fdf, (int)(floor(x) + 1), current.y,
			get_opacity(current.color, x - floor(x)));
		current.y++;
		x += delta_err;
	}
}

static void		draw_along_x(t_point start, t_point end, t_fdf *fdf,
		double delta_err)
{
	t_point		current;
	double		y;

	current = start;
	y = start.y;
	if (start.y > end.y)
		delta_err = -delta_err;
	while (current.x < end.x)
	{
		current.color = find_color(&current, &start, &end);
		put_pixel(fdf, current.x, (int)floor(y),
				get_opacity(current.color, 1 - (y - floor(y))));
		put_pixel(fdf, current.x, (int)floor(y) + 1,
				get_opacity(current.color, y - floor(y)));
		current.x++;
		y += delta_err;
	}
}

// void			draw_line(t_point start, t_point end, t_fdf *fdf)
// {
// 	double		delta_x;
// 	double		delta_y;
// 	double		delta_err;

// 	if (start.x == end.x && start.y == end.y)
// 		return ;
// 	if (start.x == end.x || start.y == end.y)
// 		straight_line(start, end, fdf);
// 	else
// 	{
// 		delta_x = fabs((double)(end.x - start.x));
// 		delta_y = fabs((double)(end.y - start.y));
// 		if (delta_x > delta_y)
// 		{
// 			delta_err = (delta_y + 1) / (delta_x + 1);
// 			start.x < end.x ?
// 				draw_along_x(start, end, fdf, delta_err) :
// 				draw_along_x(end, start, fdf, delta_err);
// 		}
// 		else
// 		{
// 			delta_err = (delta_x + 1) / (delta_y + 1);
// 			start.y < end.y ?
// 				draw_along_y(start, end, fdf, delta_err) :
// 				draw_along_y(end, start, fdf, delta_err);
// 		}
// 	}
// }

void			draw_line(t_point start, t_point end, t_fdf *fdf)
{
	double		delta_x;
	double		delta_y;
	double		delta_err;

	if (start.x == end.x || start.y == end.y)
	{
		if (start.x != end.x || start.y != end.y)
			straight_line(start, end, fdf);
		return ;
	}
	delta_x = fabs((double)(end.x - start.x));
	delta_y = fabs((double)(end.y - start.y));
	if (delta_x > delta_y)
	{
		delta_err = (delta_y + 1) / (delta_x + 1);
		start.x < end.x ?
			draw_along_x(start, end, fdf, delta_err) :
			draw_along_x(end, start, fdf, delta_err);
		return ;
	}
	delta_err = (delta_x + 1) / (delta_y + 1);
	start.y < end.y ?
		draw_along_y(start, end, fdf, delta_err) :
		draw_along_y(end, start, fdf, delta_err);
}
