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
