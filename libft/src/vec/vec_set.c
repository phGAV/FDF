/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	*vec_set(t_vec *v, ssize_t index, const void *object)
{
	t_obj	ob;
	ssize_t	n;

	n = v->size;
	if (index < 0)
		index += n;
	if ((size_t)index >= (size_t)n)
		return (NULL);
	ob = v->data + index * v->item_size;
	if (v->dtor)
		v->dtor(ob);
	if (v->ctor)
		v->ctor(ob, object);
	else
		ft_memcpy(ob, object, v->item_size);
	return (ob);
}
