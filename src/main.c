/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:06:16 by diona             #+#    #+#             */
/*   Updated: 2020/07/05 15:06:15 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_init(t_map *map, t_fdf *fdf)
{
	t_mouse		*mouse;

	if (!(mouse = ft_malloc(sizeof(t_mouse))))
		exit_err(MEMORY);
	fdf->line_size = WIN_WIDTH;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx,
			WIN_WIDTH, WIN_HEIGHT, "Fils de fer");
	fdf->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img_ptr = (int*)mlx_get_data_addr(fdf->image, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
	fdf->camera = camera_init(map);
	fdf->map = map;
	fdf->mouse = mouse;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	events_control(fdf);
}

int			main(int argc, char **argv)
{
	t_map		map;
	t_fdf		fdf;
	int			fd;

	if (argc != 2)
		exit_err(USAGE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit_err(FILE_OPEN);
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&fdf, sizeof(t_fdf));
	read_map(fd, &map);
	fdf_init(&map, &fdf);
	return (EXIT_SUCCESS);
}
