/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	*vec_filter(const t_vec *v, bool (*f)(const void *))
{
	t_vec	*u;
	t_obj	ob;
	ssize_t	size;
	size_t	item_size;

	if ((u = vec_create(1, v->item_size)))
	{
		ob = v->data;
		size = v->size;
		item_size = v->item_size;
		while (size--)
		{
			if ((*f)(ob))
				vec_append(u, ob);
			ob += item_size;
		}
	}
	return (u);
}
