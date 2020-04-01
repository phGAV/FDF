/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	*vec_resize(t_vec *v, ssize_t size)
{
	void	*data;
	ssize_t	max_size;

	max_size = v->max_size;
	if (max_size >= size && size >= max_size >> 1)
	{
		v->size = size;
		return (v);
	}
	max_size = (size + ((size_t)size >> 1) + 0x10) & ~(size_t)0x0f;
	if ((data = ft_realloc(v->data,
					max_size * v->item_size, v->size * v->item_size)))
	{
		v->data = data;
		v->size = size;
		v->max_size = max_size;
		return (v);
	}
	return (NULL);
}
