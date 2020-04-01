/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:55:41 by diona             #+#    #+#             */
/*   Updated: 2019/09/18 02:33:49 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	char	*s;
	char	*d;

	s = (char*)src;
	d = dst;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (size <= dl || size == 0)
		return (size + sl);
	while (*d != '\0')
		d++;
	size = size - dl - 1;
	while (size-- && *s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (dl + sl);
}
