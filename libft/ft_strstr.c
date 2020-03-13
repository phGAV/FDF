/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 06:21:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/15 22:29:53 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t n;

	if (!*s1 && !*s2)
		return ((char *)s1);
	if (!*s1 || !*s2)
		return (*s1 ? (char *)s1 : NULL);
	n = ft_strlen(s2);
	while (*s1)
		if (!ft_memcmp(s1++, s2, n))
			return ((char *)--s1);
	return (NULL);
}
