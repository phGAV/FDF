/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:20:21 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/20 20:41:01 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

void	*ft_malloc(size_t size)
{
	void *ptr;

	if (size == 0)
	{
		errno = EINVAL;
		return (NULL);
	}
	ptr = malloc(size);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ptr);
}
