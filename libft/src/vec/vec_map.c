/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

t_vec	*vec_map(const t_vec *v, void (*f)(void *))
{
	t_vec *u;

	u = ft_memdup(v, sizeof(t_vec));
	if (u && (u->data = ft_map(v->data, v->size, v->item_size, f)))
		return (u);
	return (ft_memdel((void **)&u));
}
