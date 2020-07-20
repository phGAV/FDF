/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	*vec_pop(t_vec *v, ssize_t index)
{
	t_obj	*ob_ref;
	void	(*dtor)(void *);
	ssize_t	n;

	n = v->size;
	if (index < 0)
		index += n;
	if ((size_t)index >= (size_t)n)
		return (NULL);
	dtor = v->dtor;
	ob_ref = ft_memdup(v->data + index * v->item_size, v->item_size);
	v->dtor = NULL;
	vec_remove(v, index);
	v->dtor = dtor;
	return (*ob_ref);
}
