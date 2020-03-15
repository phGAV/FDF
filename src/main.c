/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:57:29 by diona             #+#    #+#             */
/*   Updated: 2020/03/16 01:25:50 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *mlx)
{
	if (keycode == ESC)
		exit(0);
	mlx_loop(mlx);
	return (0);
}

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

void	draw_line_2(void *mlx, int *img_ptr, t_point *begin, t_point *end)
{
	double		delta_x;
	double		delta_y;
	double		delta_err;
	t_point		current;
	double		y;

	delta_x = fabs((double)(end->x - begin->x));
	delta_y = fabs((double)(end->y - begin->y));
	delta_err = (delta_y + 1) / (delta_x + 1);
	current = *begin;
	y = begin->y;
	if ((end->y - begin->y) < 0)
		delta_err *= -1;
	while (current.x <= end->x)
	{
		current.color = find_color(&current, begin, end);
		img_ptr[(int)(floor(y) * WIN_WIDTH + current.x)] = mlx_get_color_value(mlx, get_opacity(current.color, 1 - (y - floor(y))));
		img_ptr[(int)((floor(y) + 1) * WIN_WIDTH + current.x)] = mlx_get_color_value(mlx, get_opacity(current.color, y - floor(y)));
		current.x++;
		y += delta_err;
	}
}

/* void	draw_line(void *mlx, void *window, t_point *begin, t_point *end) */
/* { */
/* 	double		delta_x; */
/* 	double		delta_y; */
/* 	double		delta_err; */
/* 	t_point		current; */
/* 	double		y; */

/* 	delta_x = fabs((double)(end->x - begin->x)); */
/* 	delta_y = fabs((double)(end->y - begin->y)); */
/* 	delta_err = (delta_y + 1) / (delta_x + 1); */
/* 	current = *begin; */
/* 	y = begin->y; */
/* 	if ((end->y - begin->y) < 0) */
/* 		delta_err *= -1; */
/* 	while (current.x <= end->x) */
/* 	{ */
/* 		current.color = find_color(&current, begin, end); */
/* 		mlx_pixel_put(mlx, window, current.x, floor(y), get_opacity(current.color, 1 - (y - floor(y)))); */
/* 		mlx_pixel_put(mlx, window, current.x, floor(y + 1), get_opacity(current.color, y - floor(y))); */
/* 		current.x++; */
/* 		y += delta_err; */
/* 	} */
/* } */

int main(void)
{
	void		*mlx;
	void		*window;
	void		*image;
	t_point		a;
	t_point		b;
	int			bpp = 4;
	int			*img_ptr;
	int			line_size = WIN_WIDTH;
	int			endian = 0;

	a.x = 50;
	a.y = 50;
	a.color = PINK;
	b.x = 400;
	b.y = 300;
	b.color = TURQUOISE;
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "gradient and antialiasing testing");
	/* draw_line(mlx, window, &a, &b); */
	image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img_ptr = (int*)mlx_get_data_addr(image, &bpp, &line_size, &endian);
	draw_line_2(mlx, img_ptr, &a, &b);
	/* int i = 0; */
	/* while(i < 100*150) */
	/* 	img_ptr[i++] = mlx_get_color_value(mlx, WHITE); */
	mlx_put_image_to_window (mlx, window, image, 0, 0);
	mlx_key_hook(window, key_hook, mlx);
	mlx_loop(mlx);
	return (0);
}
