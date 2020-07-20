/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	vec_clear(t_vec *v)
{
	if (v->dtor)
		vec_apply(v, v->dtor);
	ft_memset(v->data, 0, v->max_size * v->item_size);
	v->size = 0;
	v->none = NULL;
	v->ctor = NULL;
	v->dtor = NULL;
}
