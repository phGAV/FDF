/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:46:04 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/27 07:54:04 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new, size_t old)
{
	void *dst;

	dst = NULL;
	if (ptr && new == 0)
		free(ptr);
	else if (ptr == NULL)
		dst = ft_malloc(new);
	else if ((dst = ft_malloc(new)))
	{
		ft_memcpy(dst, ptr, ft_umin(new, old));
		free(ptr);
	}
	return (dst);
}
