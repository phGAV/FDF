/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:45:16 by diona             #+#    #+#             */
/*   Updated: 2020/04/13 00:41:05 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int		key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == ARROW_UP)
		fdf->camera->offset_y -= OFFSET_STEP;
	if (keycode == ARROW_DOWN)
		fdf->camera->offset_y += OFFSET_STEP;
	if (keycode == ARROW_LEFT)
		fdf->camera->offset_x -= OFFSET_STEP;
	if (keycode == ARROW_RIGHT)
		fdf->camera->offset_x += OFFSET_STEP;
	if (keycode == PLUS)
		fdf->camera->ratio_z++;
	if (keycode == MINUS)
		fdf->camera->ratio_z--;
	if (keycode == I || keycode == P)
	{
		camera_reset(fdf->camera, fdf->map);
		if (keycode == P)
			fdf->camera->projection = PARALLEL;
		else
			fdf->camera->projection = ISO;
	}
	if (keycode == KEY_2)
		fdf->camera->angle_x += ANGLE_STEP;
	if (keycode == KEY_8)
		fdf->camera->angle_x -= ANGLE_STEP;
	if (keycode == KEY_4)
		fdf->camera->angle_y += ANGLE_STEP;
	if (keycode == KEY_6)
		fdf->camera->angle_y -= ANGLE_STEP;
	if (keycode == KEY_1)
		fdf->camera->angle_z += ANGLE_STEP;
	if (keycode == KEY_3)
		fdf->camera->angle_z -= ANGLE_STEP;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	if (x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (button == MOUSE_SCROLL_UP)
			fdf->camera->zoom < MAX_ZOOM ? fdf->camera->zoom++ : MAX_ZOOM;
		if (button == MOUSE_SCROLL_DOWN)
			fdf->camera->zoom > MIN_ZOOM ? fdf->camera->zoom-- : MIN_ZOOM;
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
void	events_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, key_hook, fdf);
	mlx_mouse_hook(fdf->window, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
