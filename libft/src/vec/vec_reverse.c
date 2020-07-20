/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	vec_reverse(t_vec *v)
{
	t_obj	first;
	t_obj	last;
	size_t	item_size;

	first = vec_get(v, 0);
	last = vec_get(v, -1);
	item_size = v->item_size;
	while (first < last)
	{
		ft_memswap(first, last, item_size);
		first += item_size;
		last -= item_size;
	}
}
