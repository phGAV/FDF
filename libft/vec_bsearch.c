/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_bsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	*vec_bsearch(const t_vec *v, const void *object,
			int (*cmp)(const void *, const void *))
{
	t_obj	ob;
	ssize_t	left;
	ssize_t	right;
	ssize_t	pivot;
	int		result;

	left = 0;
	right = v->size;
	while (left < right)
	{
		pivot = (left + right) / 2;
		ob = v->data + pivot * v->item_size;
		result = (*cmp)(ob, object);
		if (result < 0)
			right = pivot;
		else if (result > 0)
			left = pivot + 1;
		else
			return (ob);
	}
	return (v->none);
}
