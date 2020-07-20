/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:45:16 by diona             #+#    #+#             */
/*   Updated: 2020/07/20 20:57:01 by diona            ###   ########.fr       */
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
	{
		vec_free(fdf->map->vertex);
		free(fdf->camera);
		free(fdf->mouse);
		mlx_destroy_image(fdf->mlx, fdf->image);
		mlx_destroy_window(fdf->mlx, fdf->window);
		exit(EXIT_SUCCESS);
	}
	if (keycode <= KEYBOARD_MAX && (shortcut = g_key[keycode]))
	{
		(*shortcut)(fdf, keycode);
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	}
	return (0);
}

void	events_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, key_hook, fdf);
	mlx_hook(fdf->window, 4, 1L << 2, mouse_pressed, fdf);
	mlx_hook(fdf->window, 5, 1L << 3, mouse_released, fdf);
	mlx_hook(fdf->window, 6, 1L << 8, mouse_move, fdf);
}
