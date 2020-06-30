/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:45:16 by diona             #+#    #+#             */
/*   Updated: 2020/06/30 17:58:25 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

static const t_shortcut	g_key[KEYBOARD_MAX] = {
	[ARROW_UP] = move_up,
	[ARROW_DOWN] = move_up,
	[ARROW_LEFT] = move_side,
	[ARROW_RIGHT] = move_side,
	[PLUS] = flatten,
	[MINUS] = flatten,
	[KEY_1] = change_angle_x,
	[KEY_2] = change_angle_x,
	[KEY_3] = change_angle_y,
	[KEY_4] = change_angle_y,
	[KEY_5] = change_angle_z,
	[KEY_6] = change_angle_z,
	[I] = change_projection,
	[P] = change_projection
};

void	flatten(t_fdf *fdf, int keycode)
{
	keycode == PLUS ? fdf->camera->ratio_z++ :
		fdf->camera->ratio_z--;
}

void	change_projection(t_fdf *fdf, int keycode)
{
	camera_reset(fdf->camera, fdf->map);
	keycode == P ? fdf->camera->projection = PARALLEL : ISO;
}

void	change_angle_z(t_fdf *fdf, int keycode)
{
	keycode == KEY_5 ? fdf->camera->angle_z += ANGLE_STEP :
		(fdf->camera->angle_z -= ANGLE_STEP);
}

void	change_angle_y(t_fdf *fdf, int keycode)
{
	keycode == KEY_3 ? fdf->camera->angle_y += ANGLE_STEP :
		(fdf->camera->angle_y -= ANGLE_STEP);
}

void	change_angle_x(t_fdf *fdf, int keycode)
{
	keycode == KEY_1 ? fdf->camera->angle_x += ANGLE_STEP :
		(fdf->camera->angle_x -= ANGLE_STEP);
}

void	move_up(t_fdf *fdf, int keycode)
{
	keycode == ARROW_UP ? fdf->camera->offset_y -= OFFSET_STEP :
		(fdf->camera->offset_y += OFFSET_STEP);
}

void	move_side(t_fdf *fdf, int keycode)
{
	keycode == ARROW_RIGHT ? fdf->camera->offset_x += OFFSET_STEP :
		(fdf->camera->offset_x -= OFFSET_STEP);
}

int		key_hook(int keycode, t_fdf *fdf)
{
	t_shortcut	shortcut;

	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if ((shortcut = g_key[keycode]))
	{
		(*shortcut)(fdf, keycode);
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	}
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
