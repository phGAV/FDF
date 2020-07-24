/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:12:19 by diona             #+#    #+#             */
/*   Updated: 2020/07/20 21:55:44 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int		mouse_pressed(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->hold = true;
	else if (button == MOUSE_RIGHT_BUTTON)
		fdf->mouse->hold_rmb = true;
	else if (button == MOUSE_SCROLL_UP)
		fdf->camera->zoom < MAX_ZOOM ? fdf->camera->zoom++ : MAX_ZOOM;
	else if (button == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom > MIN_ZOOM ? fdf->camera->zoom-- : MIN_ZOOM;
	return (0);
}

int		mouse_released(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	(void)x;
	(void)y;
	fdf->mouse->hold = false;
	fdf->mouse->hold_rmb = false;
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	fdf->mouse->prev_x = fdf->mouse->x;
	fdf->mouse->prev_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->hold_rmb)
	{
		fdf->camera->angle_x -= (y - fdf->mouse->prev_y) * ANGLE_STEP;
		fdf->camera->angle_z -= (x - fdf->mouse->prev_x) * ANGLE_STEP;
	}
	else if (fdf->mouse->hold)
	{
		fdf->camera->offset_y -= fdf->mouse->prev_y - y;
		fdf->camera->offset_x -= fdf->mouse->prev_x - x;
	}
	return (0);
}
