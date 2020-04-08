/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:45:16 by diona             #+#    #+#             */
/*   Updated: 2020/04/09 00:32:55 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"
#define OFFSET_STEP 10
         // expose_hook(void *param);
         // key_hook(int keycode,void *param);
         // mouse_hook(int button,int x,int y,void *param);
         // loop_hook(void *param);

// mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
int		key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit(0);
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
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	if (button == MOUSE_SCROLL_UP)
		fdf->camera->zoom++;
	if (button == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom--;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
void	events_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, key_hook, fdf);
	mlx_mouse_hook(fdf->window, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
