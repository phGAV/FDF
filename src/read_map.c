/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 00:59:37 by diona             #+#    #+#             */
/*   Updated: 2020/04/11 01:05:24 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	myatoi(void *elem, const char *begin, const char *end)
{
	int		n;
	int		neg;

	n = 0;
	neg = 1;
	if (*begin == '-' || *begin == '+')
	{
		if (*begin == '-')
			neg = -neg;
		begin++;
	}
	while (ft_isdigit(*begin))
		n = n * 10 + *begin++ - '0';
	if (begin != end)
		exit_err(MAP_ERR);
	*(int *)elem = neg * n;
}

void		read_map(int fd, t_map *map)
{
	t_vec	*v_num;
	t_vec	*v_add;
	char	*line;
	int		gnl;
	ssize_t	x;
	ssize_t	y;

	while ((gnl = get_next_line(fd, &line)))
	{
		map->height++;
		if (map->height == 1)
		{
			v_num = vec_import(line, ' ', sizeof(int), myatoi);
			map->width = v_num->size;
		}
		else
		{
			v_add = vec_import(line, ' ', sizeof(int), myatoi);
			vec_extend(v_num, v_add);
			if (map->width != v_add->size)
				exit_err(MAP_ERR);
			vec_free(v_add);
		}
		ft_strdel(&line);
	}
	y = 0;
	if (!(map->vertex = ft_malloc(sizeof(int *) * map->height)))
		exit_err(MEMORY);
	while (y < map->height)
	{
		if (!(map->vertex[y] = ft_malloc(sizeof(int) * map->width)))
			exit_err(MEMORY);
		x = 0;
		while (x < map->width)
		{
			map->vertex[y][x] = *(int *)vec_get(v_num, y * map->width + x);
			if (map->vertex[y][x] > map->max_z)
				map->max_z = map->vertex[y][x];
			if (map->vertex[y][x] < map->min_z)
				map->min_z = map->vertex[y][x];
			x++;
		}
		y++;
	}
	// y = 0;
	// while (y < map->height)
	// {
	// 	x = 0;
	// 	while (x < map->width)
	// 	{
	// 		printf("%3d", map->vertex[y][x]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	vec_free(v_num);
	close(fd);
	if (gnl < 0)
		exit_err(MAP_ERR);
}
