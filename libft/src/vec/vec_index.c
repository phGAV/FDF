/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

ssize_t	vec_index(const t_vec *v, const void *object)
{
	t_obj	ob;
	ssize_t	size;
	size_t	item_size;
	ssize_t	index;

	ob = v->data;
	size = v->size;
	item_size = v->item_size;
	index = 0;
	while (index < size)
	{
		if (ft_memcmp(ob, object, item_size) == 0)
			return (index);
		ob += item_size;
		index++;
	}
	return (ENOINDEX);
}
