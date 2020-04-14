/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:21:21 by diona             #+#    #+#             */
/*   Updated: 2020/04/14 02:15:59 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			color_blend(int begin, int end, double percentage)
{
    return ((int)((1 - percentage) * begin + percentage * end));
}

int		color_from_percentage(int start, int end, double percentage)
{
	int		red;
	int		green;
	int		blue;

	red = color_blend((start >> 16) & 0xff, (end >> 16) & 0xff, percentage);
	green = color_blend((start >> 8) & 0xff, (end >> 8) & 0xff, percentage);
	blue = color_blend(start & 0xff, end & 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		find_color(t_point *current, t_point *begin, t_point *end)
{
	double	percentage;

	if (abs(end->x - begin->x) > abs(end->y - begin->y))
		percentage = ((end->x - begin->x) == 0) ? 1.0 :
			((double)(current->x - begin->x) / (double)(end->x - begin->x));
	else
		percentage = ((end->y - begin->y) == 0) ? 1.0 :
			((double)(current->y - begin->y) / (double)(end->y - begin->y));
	return (color_from_percentage(begin->color, end->color, percentage));
}

int		find_vertex_color(int max, int min, int current)
{
	double	percentage;

	percentage = (max - min == 0) ? 1.0 :
		((double)(current - min) / (double)(max - min));
	return (color_from_percentage(PINK, TURQUOISE, percentage));
}

int		get_opacity(int color, double opacity)
{
	int		alpha;

	alpha = floor(0xff * (1 - opacity));
	return ((alpha << 24) | color);
}

void		put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		fdf->img_ptr[y * WIN_WIDTH + x] =
			mlx_get_color_value(fdf->mlx, color);
	}
}

static void	straight_line(t_point start, t_point end, t_fdf *fdf)
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

void		draw_along_y(t_point start, t_point end, t_fdf *fdf,
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

void		draw_along_x(t_point start, t_point end, t_fdf *fdf,
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

void	set_background(t_fdf *fdf)
{
	ft_bzero(fdf->img_ptr, sizeof(int) * WIN_WIDTH * WIN_HEIGHT);
}

void		draw_line(t_point start, t_point end, t_fdf *fdf)
{
	double		delta_x;
	double		delta_y;
	double		delta_err;

	if (start.x == end.x && start.y == end.y)
		return ;
	if (start.x == end.x || start.y == end.y)
		straight_line(start, end, fdf);
	else
	{
		delta_x = fabs((double)(end.x - start.x));
		delta_y = fabs((double)(end.y - start.y));
		if (delta_x > delta_y)
		{
			delta_err = (delta_y + 1) / (delta_x + 1);
			start.x < end.x ?
				draw_along_x(start, end, fdf, delta_err) :
				draw_along_x(end, start, fdf, delta_err);
		}
		else
		{
			delta_err = (delta_x + 1) / (delta_y + 1);
			start.y < end.y ?
				draw_along_y(start, end, fdf, delta_err) :
				draw_along_y(end, start, fdf, delta_err);
		}
	}
}
