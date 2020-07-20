/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"
#include "internal.h"

void	*vec_insert(t_vec *v, ssize_t index, const void *object)
{
	void	*data;
	t_obj	ob;
	size_t	item_size;
	ssize_t	n;

	n = v->size;
	if (!vec_resize(v, n + 1))
		return (NULL);
	if (index < 0)
		if ((index += n) < 0)
			index = 0;
	if (index > n)
		index = n;
	data = v->data;
	item_size = v->item_size;
	while (--n >= index)
		ft_memcpy(data + (n + 1) * item_size,
				data + n * item_size, item_size);
	ob = data + index * item_size;
	if (v->ctor)
		v->ctor(ob, object);
	else
		ft_memcpy(ob, object, item_size);
	return (ob);
}
