/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:40:14 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 15:11:24 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			*d = *s;
			return (++d);
		}
		*d++ = *s++;
	}
	return (NULL);
}
