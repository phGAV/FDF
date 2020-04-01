/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

t_vec	*vec_create(size_t size, size_t item_size)
{
	t_vec	*v;
	void	*data;

	v = ft_malloc(sizeof(t_vec));
	if (v && (data = ft_malloc(size * item_size)))
	{
		ft_memset(v, 0, sizeof(t_vec));
		v->data = data;
		v->item_size = item_size;
		v->max_size = size;
		return (v);
	}
	return (ft_memdel((void **)&v));
}
