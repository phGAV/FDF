/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:06:16 by diona             #+#    #+#             */
/*   Updated: 2020/07/20 20:55:13 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// [ ] norme
// [ ] line draw
// [x] change color
// [?] view offset
// [ ] map is CRAZY, i like it a lot
// [x] menu
// [x] do not redraw on click
// [ ] correct skew

void		fdf_init(t_fdf *fdf)
{
	fdf->line_size = WIN_WIDTH;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx,
			WIN_WIDTH + MENU_WIDTH, WIN_HEIGHT, "Fils de fer");
	fdf->menu = mlx_new_image(fdf->mlx, MENU_WIDTH, WIN_HEIGHT);
	fdf->menu_ptr = (int*)mlx_get_data_addr(fdf->menu, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
	fdf->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img_ptr = (int*)mlx_get_data_addr(fdf->image, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
}

int			main(int argc, char **argv)
{
	t_fdf		fdf;
	t_map		map;
	t_mouse		mouse;
	t_camera	camera;
	int			fd;

	if (argc != 2)
		exit_err(USAGE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit_err(FILE_OPEN);
	ft_memset(&fdf, 0, sizeof(t_fdf));
	fdf.map = ft_memset(&map, 0, sizeof(t_map));
	map.lo_color = PINK;
	map.hi_color = TURQUOISE;
	fdf.mouse = ft_memset(&mouse, 0, sizeof(t_mouse));
	fdf.camera = ft_memset(&camera, 0, sizeof(t_mouse));
	read_map(fd, &map);
	close(fd);
	camera_init(&camera, &map);
	fdf_init(&fdf);
	// draw_map(&fdf);
	draw_menu(&fdf);
	events_control(&fdf);
	mlx_loop_hook(fdf.mlx, (int (*)())draw_map, &fdf);
	mlx_loop(fdf.mlx);
	return (EXIT_SUCCESS);
}
