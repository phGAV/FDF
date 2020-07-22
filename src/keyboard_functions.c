/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:45:34 by diona             #+#    #+#             */
/*   Updated: 2020/07/02 23:46:20 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

void	flatten(t_fdf *fdf, int keycode)
{
	keycode == PLUS ? fdf->camera->ratio_z++ :
		fdf->camera->ratio_z--;
}

void	change_projection(t_fdf *fdf, int keycode)
{
	fdf->camera->projection = keycode == P ? PARALLEL : ISO;
	camera_init(fdf->camera, fdf->map);
}

int		hsv_to_rgb(int h, int s, int v)
{
	const int	i = (int)(h / 60);
	const float	f = h - i;
	const int	p = v * (1.0 - s);
	const int	q = v * (1.0 - s * f);
	const int	t = v * (1.0 - s * (1.0 - f));

	if (i == 0)
		return (v << 16 | t << 8 | p);
	if (i == 1)
		return (q << 16 | v << 8 | p);
	if (i == 2)
		return (p << 16 | v << 8 | t);
	if (i == 3)
		return (p << 16 | q << 8 | v);
	if (i == 4)
		return (t << 16 | p << 8 | v);
	return (v << 16 | p << 8 | q);
}

void	change_colors(t_fdf *fdf, int keycode)
{
	const int hue = rand() % 360;
	(void)keycode;
	fdf->map->lo_color = hsv_to_rgb(hue, 74, 100);
	fdf->map->hi_color = hsv_to_rgb(360 - hue, 74, 100);
}

void	change_blur(t_fdf *fdf, int keycode)
{
	(void)keycode;
	fdf->map->bg_color = fdf->map->bg_color ? BG_SOLID : BG_BLUR;
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
