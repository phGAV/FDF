/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	*vec_get(const t_vec *v, ssize_t index)
{
	ssize_t n;

	n = v->size;
	if (index < 0)
		index += n;
	if ((size_t)index >= (size_t)n)
		return (v->none);
	return (v->data + index * v->item_size);
}
