/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:53:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 22:11:13 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static inline void	*lomuto(void *left, void *right, size_t size,
		int (*cmp)(const void *, const void *))
{
	void *pivot;
	void *i;
	void *j;

	pivot = right;
	i = left;
	j = left;
	while (j < right)
	{
		if ((*cmp)(j, pivot) <= 0)
		{
			ft_memswap(i, j, size);
			i += size;
		}
		j += size;
	}
	ft_memswap(i, right, size);
	return (i);
}

static void			quick_sort(void *left, void *right, size_t size,
		int (*cmp)(const void *, const void *))
{
	void *pivot;

	if (left < right)
	{
		pivot = lomuto(left, right, size, cmp);
		quick_sort(left, pivot - size, size, cmp);
		quick_sort(pivot + size, right, size, cmp);
	}
}

/*
** @data: pointer to array
** @len:  amount of elements
** @size: element's sizeof
** @cmp:  compare function
*/

void				ft_qsort(void *data, size_t len, size_t size,
		int (*cmp)(const void *, const void *))
{
	void *left;
	void *right;

	left = data;
	right = data + (len - 1) * size;
	quick_sort(left, right, size, cmp);
}
