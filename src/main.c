/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:06:16 by diona             #+#    #+#             */
/*   Updated: 2020/04/09 00:25:44 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*camera_init(t_map *map)
{
	t_camera	*camera;
	int			y_scale;
	int			x_scale;

	camera = ft_malloc(sizeof(t_camera));
	y_scale = WIN_HEIGHT / map->height / 2;
	x_scale = WIN_WIDTH / map->width / 2;
	camera->projection = ISO;
	camera->angle_x = 0;
	camera->angle_y = 0;
	camera->angle_z = 0;
	camera->zoom = x_scale > y_scale ? y_scale : x_scale;
	camera->ratio_z = (WIN_HEIGHT - map->height * camera->zoom) /
		(map->max_z - map->min_z) / 4;
	camera->offset_x = 0;
	camera->offset_y = 0;
	return (camera);
}

void	fdf_init(t_map *map, t_fdf *fdf)
{
	fdf->line_size = WIN_WIDTH;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx,
			WIN_WIDTH, WIN_HEIGHT, "Fils de fer");
	fdf->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img_ptr = (int*)mlx_get_data_addr(fdf->image, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
	fdf->camera = camera_init(map);
	fdf->map = map;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	events_control(fdf);
	// mlx_loop(fdf->mlx);
}

int main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;

	if (argc != 2)
		exit_err(USAGE);
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&fdf, sizeof(t_fdf));
	read_map(argv[1], &map);
	fdf_init(&map, &fdf);
	return (0);
}
