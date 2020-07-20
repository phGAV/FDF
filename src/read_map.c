/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 00:59:37 by diona             #+#    #+#             */
/*   Updated: 2020/07/20 20:54:49 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		myatoi(void *elem, const char *begin, const char *end)
{
	int			n;
	int			neg;

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

static void		min_max(t_map *map)
{
	int			val;
	int			i;

	i = 0;
	while (i < map->width * map->height)
	{
		val = *(int *)vec_get(map->vertex, i);
		i++;
		if (val < map->min_z)
			map->min_z = val;
		if (val > map->max_z)
			map->max_z = val;
	}
}

void			read_map(int fd, t_map *map)
{
	t_vec		*v_add;
	char		*line;
	int			gnl;

	if ((gnl = get_next_line(fd, &line)) > 0)
	{
		map->vertex = vec_import(line, ' ', sizeof(int), myatoi);
		map->width = map->vertex->size;
		map->height++;
		ft_strdel(&line);
	}
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		v_add = vec_import(line, ' ', sizeof(int), myatoi);
		if (map->width != v_add->size)
			exit_err(MAP_ERR);
		map->height++;
		vec_extend(map->vertex, v_add);
		vec_free(v_add);
		ft_strdel(&line);
	}
	if (gnl < 0)
		exit_err(MAP_ERR);
	min_max(map);
	free(line);
}
