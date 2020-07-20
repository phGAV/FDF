/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_remove.c                                       :+:      :+:    :+:   */
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

void	*vec_remove(t_vec *v, ssize_t index)
{
	void	*data;
	t_obj	ob;
	size_t	item_size;
	ssize_t	n;

	n = v->size;
	if (index < 0)
		index += n;
	if ((size_t)index >= (size_t)n)
		return (NULL);
	if (!vec_resize(v, n - 1))
		return (NULL);
	data = v->data;
	item_size = v->item_size;
	ob = data + index * item_size;
	if (v->dtor)
		v->dtor(ob);
	while (++index < n)
		ft_memcpy(data + (index - 1) * item_size,
				data + index * item_size, item_size);
	return (ob);
}
