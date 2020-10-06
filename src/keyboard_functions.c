/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:45:34 by diona             #+#    #+#             */
/*   Updated: 2020/07/25 19:16:05 by diona            ###   ########.fr       */
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

void	change_angle_z(t_fdf *fdf, int keycode)
{
	fdf->camera->angle_z += keycode == KEY_5 ? ANGLE_STEP : -ANGLE_STEP;
}

void	change_angle_y(t_fdf *fdf, int keycode)
{
	fdf->camera->angle_y += keycode == KEY_3 ? ANGLE_STEP : -ANGLE_STEP;
}

void	change_angle_x(t_fdf *fdf, int keycode)
{
	fdf->camera->angle_x += keycode == KEY_1 ? ANGLE_STEP : -ANGLE_STEP;
}
