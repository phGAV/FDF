/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

size_t	vec_count(const t_vec *v, const void *object)
{
	t_obj	ob;
	ssize_t	size;
	size_t	item_size;
	size_t	count;

	ob = v->data;
	size = v->size;
	item_size = v->item_size;
	count = 0;
	while (size--)
	{
		if (ft_memcmp(ob, object, item_size) == 0)
			count++;
		ob += item_size;
	}
	return (count);
}
