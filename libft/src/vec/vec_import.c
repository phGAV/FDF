/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

t_vec	*vec_import(const char *s, int delim, size_t item_size,
				void (*f)(void *, const char *, const char *))
{
	t_vec	*v;
	t_obj	ob;
	ssize_t	size;
	char	*s0;

	size = ft_strelems(s, delim);
	if ((v = vec_create(size, item_size)))
	{
		v->size = size;
		ob = v->data;
		while (size--)
		{
			s0 = ft_strjmp((char **)&s, delim);
			(*f)(ob, s0, s);
			ob += item_size;
		}
	}
	return (v);
}
