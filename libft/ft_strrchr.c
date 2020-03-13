/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 05:06:19 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/13 01:06:51 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	if (!c)
		return ((char *)s + ft_strlen(s));
	p = s + ft_strlen(s);
	while (s <= p--)
		if (*p == (char)c)
			return ((char *)p);
	return (NULL);
}
