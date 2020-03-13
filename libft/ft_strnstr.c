/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 06:25:52 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/25 07:18:18 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (!*s1 && !*s2)
		return ((char *)s1);
	if (!*s1 || !*s2)
		return (*s1 ? (char *)s1 : NULL);
	len = ft_strlen(s2);
	while (*s1 && n-- >= len)
		if (!ft_memcmp(s1++, s2, len))
			return ((char *)--s1);
	return (NULL);
}
