/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:21:21 by diona             #+#    #+#             */
/*   Updated: 2020/04/13 00:27:57 by diona            ###   ########.fr       */
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

static void	straight_line(t_point start, t_point end, t_fdf *fdf)
{
	t_point		current;
	int			delta;

	delta = 1;
	current = start;
	if (start.x > end.x || start.y > end.y)
		delta *= -1;
	if (start.x == end.x && current.x < WIN_WIDTH && current.x >= 0)
	{
		current.y += delta;
		while (current.y != end.y)
		{
			if (current.y < WIN_HEIGHT && current.y >= 0)
			{
				current.color = find_color(&current, &start, &end);
				fdf->img_ptr[current.y * WIN_WIDTH + current.x] =
					mlx_get_color_value(fdf->mlx, current.color);
			}
			current.y += delta;
		}
	}
	else if (start.y == end.y && current.y < WIN_HEIGHT && current.y >= 0)
	{
		current.x += delta;
		while (current.x != end.x)
		{
			if (current.x < WIN_WIDTH && current.x >= 0)
			{
				current.color = find_color(&current, &start, &end);
				fdf->img_ptr[current.y * WIN_WIDTH + current.x] =
					mlx_get_color_value(fdf->mlx, current.color);
			}
			current.x += delta;
		}
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
		if (current.y >= 0 && current.y < WIN_HEIGHT && x >= 0 && x < WIN_WIDTH)
		{
			current.color = find_color(&current, &start, &end);
			fdf->img_ptr[(int)(current.y * WIN_WIDTH + floor(x))] =
				mlx_get_color_value(fdf->mlx,
						get_opacity(current.color, 1 - (x - floor(x))));
			fdf->img_ptr[(int)(current.y * WIN_WIDTH + floor(x) + 1)] =
				mlx_get_color_value(fdf->mlx,
						get_opacity(current.color, x - floor(x)));
		}
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
		if (current.x >= 0 && current.x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		{
			current.color = find_color(&current, &start, &end);
			fdf->img_ptr[(int)(floor(y) * WIN_WIDTH + current.x)] =
				mlx_get_color_value(fdf->mlx,
						get_opacity(current.color, 1 - (y - floor(y))));
			fdf->img_ptr[(int)((floor(y) + 1) * WIN_WIDTH + current.x)] =
				mlx_get_color_value(fdf->mlx,
						get_opacity(current.color, y - floor(y)));
		}
		current.x++;
		y += delta_err;
	}
}

void		put_pixels_on_ends(t_point start,t_point end, t_fdf *fdf)
{
	if (start.y >= 0 && start.x >= 0 &&
			start.y < WIN_HEIGHT && start.x < WIN_WIDTH)
		fdf->img_ptr[start.y * WIN_WIDTH + start.x] =
			mlx_get_color_value(fdf->mlx, start.color);
	if (end.y >= 0 && end.x >= 0 &&
			end.y < WIN_HEIGHT && end.x < WIN_WIDTH)
		fdf->img_ptr[end.y * WIN_WIDTH + end.x] =
			mlx_get_color_value(fdf->mlx, end.color);
}

void	set_background(t_fdf *fdf)
{
	// int	i;

	ft_bzero(fdf->img_ptr, sizeof(int) * WIN_WIDTH * WIN_HEIGHT);
	// i = 0;
	// while (i < WIN_WIDTH * WIN_HEIGHT)
	// 	fdf->back_ptr[i++] = mlx_get_color_value(fdf->mlx, BACKGROUND);
}

void		draw_line(t_point start, t_point end, t_fdf *fdf)
{
	double		delta_x;
	double		delta_y;
	double		delta_err;

	put_pixels_on_ends(start, end, fdf);
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
