/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 08:00:44 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/18 19:46:23 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank_l(int c)
{
	return (ft_isblank(c) || (unsigned)c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char *p0;
	char *p1;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	p0 = (char *)s;
	p1 = (char *)s + ft_strlen(s);
	while (ft_isblank_l(*p0))
		p0++;
	if (p0 == p1)
		return (ft_strnew(0));
	while (ft_isblank_l(*--p1))
		continue ;
	return (ft_strndup(p0, p1 - p0 + 1));
}
