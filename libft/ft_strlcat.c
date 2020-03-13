/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 03:17:05 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/17 23:52:25 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t sl;
	size_t dl;
	size_t n;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (size <= dl)
		return (size + sl);
	n = sl < size - dl ? sl : size - dl - 1;
	ft_strncat(dst + dl, src, n);
	return (dl + sl);
}
