/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:56:48 by diona             #+#    #+#             */
/*   Updated: 2019/09/15 22:33:55 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;
	size_t	i;
	char	*h;

	l = ft_strlen(needle);
	i = len;
	h = (char*)haystack;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && i--)
	{
		if (ft_memcmp(haystack, needle, l) == 0)
		{
			if (haystack + l > h + len)
				return (NULL);
			else
				return ((char*)haystack);
		}
		else
			haystack++;
	}
	return (NULL);
}
