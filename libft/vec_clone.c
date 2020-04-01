/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

t_vec	*vec_clone(const t_vec *v)
{
	t_vec *u;

	u = ft_memdup(v, sizeof(t_vec));
	if (u && (u->data = ft_memdup(v->data, v->size * v->item_size)))
		return (u);
	return (ft_memdel((void **)&u));
}
