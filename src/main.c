/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:06:16 by diona             #+#    #+#             */
/*   Updated: 2020/04/03 16:38:00 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_map *map, t_fdf *fdf)
{
	fdf->line_size = WIN_WIDTH;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx,
			WIN_WIDTH, WIN_HEIGHT, "Fils de fer");
	fdf->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img_ptr = (int*)mlx_get_data_addr(fdf->image, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
	draw_map(map, fdf);
	mlx_put_image_to_window (fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_key_hook(fdf->window, key_hook, fdf->mlx);
	mlx_loop(fdf->mlx);
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
