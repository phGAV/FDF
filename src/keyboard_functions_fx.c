/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions_fx.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:45:34 by diona             #+#    #+#             */
/*   Updated: 2020/07/02 23:46:20 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

static int	hsv_to_rgb(float h, float s, float v)
{
	const int	i = (int)trunc(h / 60);
	const float	f = h / 60 - i;
	const float	p = v * (1.0 - s);
	const float	q = v * (1.0 - s * f);
	const float	t = v * (1.0 - s * (1.0 - f));

	if (i == 0)
		return ((int)(255 * v) << 16 | (int)(255 * t) << 8 | (int)(255 * p));
	if (i == 1)
		return ((int)(255 * q) << 16 | (int)(255 * v) << 8 | (int)(255 * p));
	if (i == 2)
		return ((int)(255 * p) << 16 | (int)(255 * v) << 8 | (int)(255 * t));
	if (i == 3)
		return ((int)(255 * p) << 16 | (int)(255 * q) << 8 | (int)(255 * v));
	if (i == 4)
		return ((int)(255 * t) << 16 | (int)(255 * p) << 8 | (int)(255 * v));
	return ((int)(255 * v) << 16 | (int)(255 * p) << 8 | (int)(255 * q));
}

void		change_colors(t_fdf *fdf, int keycode)
{
	const int hue = ft_rand() % 180 + 1;

	(void)keycode;
	fdf->map->lo_color = hsv_to_rgb(hue, 0.74, 0.81);
	fdf->map->hi_color = hsv_to_rgb(hue + ft_rand() % 180, 0.74, 0.81);
}

void		change_blur(t_fdf *fdf, int keycode)
{
	(void)keycode;
	fdf->map->bg_color = fdf->map->bg_color ? BG_SOLID : BG_BLUR;
}
