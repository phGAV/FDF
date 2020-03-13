/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:02:25 by ourgot            #+#    #+#             */
/*   Updated: 2019/10/12 14:30:34 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = dst;
	ps = src;
	if (!pd && !ps)
		return (NULL);
	if (pd < ps)
		while (n--)
			*pd++ = *ps++;
	else if (pd > ps)
	{
		pd += n;
		ps += n;
		while (n--)
			*--pd = *--ps;
	}
	return (dst);
}
