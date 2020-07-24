/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:45:16 by diona             #+#    #+#             */
/*   Updated: 2020/07/20 22:03:31 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

static const t_shortcut	g_key[KEYBOARD_MAX] = {
	[ESC] = (t_shortcut)close_hook,
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
	[C] = change_colors,
	[M] = change_blur,
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

int		close_hook(t_fdf *fdf, int keycode)
{
	(void)keycode;
	mlx_destroy_image(fdf->mlx, fdf->menu);
	mlx_destroy_image(fdf->mlx, fdf->image);
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(EXIT_SUCCESS);
}

int		key_hook(int keycode, t_fdf *fdf)
{
	t_shortcut	shortcut;

	if (keycode <= KEYBOARD_MAX && (shortcut = g_key[keycode]))
		(*shortcut)(fdf, keycode);
	return (0);
}

void	events_control(t_fdf *fdf)
{
	mlx_hook(fdf->window, DESTROY_NOTIFY, 0, close_hook, fdf);
	mlx_hook(fdf->window, KEY_PRESS, 1, key_hook, fdf);
	mlx_hook(fdf->window, BUTTON_PRESS, 1L << 2, mouse_pressed, fdf);
	mlx_hook(fdf->window, BUTTON_RELEASE, 1L << 3, mouse_released, fdf);
	mlx_hook(fdf->window, MOTION_NOTIFY, 1L << 8, mouse_move, fdf);
}
