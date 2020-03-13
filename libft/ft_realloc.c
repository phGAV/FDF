/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:46:04 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/27 07:54:04 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t sz_src, size_t sz_dst)
{
	void *dst;

	if (!src)
		return (NULL);
	if ((dst = malloc(sz_dst)))
	{
		ft_memcpy(dst, src, sz_src);
		ft_memdel(&src);
	}
	return (dst);
}
