/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:21:21 by diona             #+#    #+#             */
/*   Updated: 2020/04/02 02:28:48 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			color_blend(int begin, int end, double percentage)
{
    return ((int)((1 - percentage) * begin + percentage * end));
}

int		find_color(t_point *current, t_point *begin, t_point *end)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	if (abs(end->x - begin->x) > abs(end->y - begin->y))
		percentage = ((end->x - begin->x) == 0) ? 1.0 :
			((double)(current->x - begin->x) / (double)(end->x - begin->x));
	else
		percentage = ((end->y - begin->y) == 0) ? 1.0 :
			((double)(current->y - begin->y) / (double)(end->y - begin->y));
	red = color_blend((begin->color >> 16) & 0xff, (end->color >> 16) & 0xff, percentage);
	green = color_blend((begin->color >> 8) & 0xff, (end->color >> 8) & 0xff, percentage);
	blue = color_blend((begin->color) & 0xff, (end->color) & 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		get_opacity(int color, double opacity)
{
	int		alpha;

	alpha = floor(0xff * (1 - opacity));
	return ((alpha << 24) | color);
}

static void		swap_points(t_point *start, t_point *end)
{
	t_point	tmp;

	tmp = *start;
	start = end;
	end = &tmp;
}

static void	straight_line(t_point start, t_point end, t_fdf *fdf)
{
	t_point		current;
	// int			y;
	// int			x;
	int			delta;

	delta = 1;
	current = start;
	if (start.x > end.x || start.y > end.y)
		delta *= -1;
	if (start.x == end.x)
	{
		while (current.y <= end.y)
		{
			current.color = find_color(&current, &start, &end);
			fdf->img_ptr[current.y * WIN_WIDTH + current.x] =
				mlx_get_color_value(fdf->mlx, current.color);
			current.y += delta;
		}
	}
	else if (start.y == end.y)
	{
		while (current.x <= end.x)
		{
			current.color = find_color(&current, &start, &end);
			fdf->img_ptr[current.y * WIN_WIDTH + current.x] =
				mlx_get_color_value(fdf->mlx, current.color);
			current.x += delta;
		}
	}
}

void		draw_line(t_point start, t_point end, t_fdf *fdf)
{
	double		delta_x;
	double		delta_y;
	double		delta_err;
	t_point		current;
	double		y;

	if (start.x == end.x || start.y == end.y)
		straight_line(start, end, fdf);
	else
	{
		if (end.x < start.x)
			swap_points(&start, &end);
		delta_x = fabs((double)(end.x - start.x));
		delta_y = fabs((double)(end.y - start.y));
		if (delta_x > delta_y)
		{
			delta_err = (delta_y + 1) / (delta_x + 1);
			current = start;
			y = start.y;
			if (end.y < start.y)
				delta_err *= -1;
			while (current.x <= end.x)
			{
				current.color = find_color(&current, &start, &end);
				fdf->img_ptr[(int)(floor(y) * WIN_WIDTH + current.x)] =
					mlx_get_color_value(fdf->mlx,
							get_opacity(current.color, 1 - (y - floor(y))));
				fdf->img_ptr[(int)((floor(y) + 1) * WIN_WIDTH + current.x)] =
					mlx_get_color_value(fdf->mlx,
							get_opacity(current.color, y - floor(y)));
				current.x++;
				y += delta_err;
			}
		}
		else
		{
			double x;
			delta_err = (delta_x + 1) / (delta_y + 1);
			current = start;
			x = start.x;
			if (end.x < start.x)
				delta_err *= -1;
			while (current.y <= end.y)
			{
				current.color = find_color(&current, &start, &end);
				fdf->img_ptr[(int)(current.x * WIN_WIDTH + floor(x))] =
					mlx_get_color_value(fdf->mlx,
							get_opacity(current.color, 1 - (x - floor(x))));
				fdf->img_ptr[(int)(current.y * WIN_WIDTH + floor(x) + 1)] =
					mlx_get_color_value(fdf->mlx,
							get_opacity(current.color, x - floor(x)));
				current.y++;
				x += delta_err;
			}
		}
	}
}
