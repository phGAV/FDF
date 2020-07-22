/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:04:14 by diona             #+#    #+#             */
/*   Updated: 2020/07/05 15:04:42 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		camera_init(t_camera *camera, t_map *map)
{
	int			y_scale;
	int			x_scale;

	camera->angle_x = 0;
	camera->angle_y = 0;
	camera->angle_z = 0;
	camera->offset_x = 0;
	camera->offset_y = 0;
	y_scale = WIN_HEIGHT / map->height / 2;
	x_scale = WIN_WIDTH / map->width / 2;
	camera->zoom = x_scale > y_scale ? y_scale : x_scale;
	camera->ratio_z = (map->max_z - map->min_z == 0) ? 1 :
		(WIN_HEIGHT - map->height * camera->zoom) /
		(map->max_z - map->min_z) / 2;
	if (camera->projection == ISO)
		camera->offset_y += abs(map->max_z + map->min_z) * camera->zoom / 2;
}
