/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"
#include "internal.h"

t_vec	*vec_extend(t_vec *v, const t_vec *u)
{
	ssize_t size;

	size = v->size;
	if (!vec_resize(v, size + u->size))
		return (NULL);
	ft_memcpy(v->data + size * v->item_size,
			u->data, u->size * u->item_size);
	return (v);
}
