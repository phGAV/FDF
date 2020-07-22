/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:18:12 by diona             #+#    #+#             */
/*   Updated: 2020/07/05 16:21:26 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_blend(int begin, int end, double percentage)
{
	return ((int)((1 - percentage) * begin + percentage * end));
}

static int	color_from_percentage(int start, int end, double percentage)
{
	int		red;
	int		green;
	int		blue;

	red = color_blend((start >> 16) & 0xff, (end >> 16) & 0xff, percentage);
	green = color_blend((start >> 8) & 0xff, (end >> 8) & 0xff, percentage);
	blue = color_blend(start & 0xff, end & 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int			find_color(t_point *current, t_point *begin, t_point *end)
{
	double	percentage;

	if (abs(end->x - begin->x) > abs(end->y - begin->y))
		percentage = ((end->x - begin->x) == 0) ? 1.0 :
			((double)(current->x - begin->x) / (double)(end->x - begin->x));
	else
		percentage = ((end->y - begin->y) == 0) ? 1.0 :
			((double)(current->y - begin->y) / (double)(end->y - begin->y));
	return (color_from_percentage(begin->color, end->color, percentage));
}

int			find_vertex_color(t_map *map, int max, int min, int current)
{
	double	percentage;

	percentage = (max - min == 0) ? 1.0 :
		((double)(current - min) / (double)(max - min));
	// return (color_from_percentage(PINK, TURQUOISE, percentage));
	return (color_from_percentage(map->lo_color, map->hi_color, percentage));
}

int			get_opacity(int color, double opacity)
{
	int		alpha;

	alpha = floor(0xff * (1 - opacity));
	return ((alpha << 24) | color);
}
