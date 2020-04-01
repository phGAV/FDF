/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	*vec_search(const t_vec *v, const void *object)
{
	t_obj	ob;
	ssize_t	size;
	size_t	item_size;

	ob = v->data;
	size = v->size;
	item_size = v->item_size;
	while (size--)
	{
		if (ft_memcmp(ob, object, item_size) == 0)
			return (ob);
		ob += item_size;
	}
	return (v->none);
}
