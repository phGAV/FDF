/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

t_vec	*vec_extract(const t_vec *v, ssize_t index, size_t size)
{
	t_vec	*u;
	ssize_t	n;

	n = v->size;
	if (index < 0)
		index += n;
	if ((size_t)index >= (size_t)n)
		return (NULL);
	size = ft_imin(size, n - index);
	if ((u = vec_create(size, v->item_size)))
	{
		u->size = size;
		ft_memcpy(u->data, v->data + index * v->item_size, size * v->item_size);
	}
	return (u);
}
