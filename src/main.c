/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:06:16 by diona             #+#    #+#             */
/*   Updated: 2020/06/05 00:57:23 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		camera_reset(t_camera *camera, t_map *map)
{
	int			y_scale;
	int			x_scale;

	ft_bzero(camera, sizeof(t_camera));
	y_scale = WIN_HEIGHT / map->height / 2;
	x_scale = WIN_WIDTH / map->width / 2;
	camera->zoom = x_scale > y_scale ? y_scale : x_scale;
	camera->ratio_z = (map->max_z - map->min_z == 0) ? 1 :
		(WIN_HEIGHT - map->height * camera->zoom) /
		(map->max_z - map->min_z) / 2;
}

t_camera	*camera_init(t_map *map)
{
	t_camera	*camera;

	if (!(camera = ft_malloc(sizeof(t_camera))))
		exit_err(MEMORY);
	camera_reset(camera, map);
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
}

int main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		exit_err(USAGE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit_err(FILE_OPEN);
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&fdf, sizeof(t_fdf));
	read_map(fd, &map);
	fdf_init(&map, &fdf);
	return (0);
}
