/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 00:07:53 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 20:37:35 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, len) == 0)
			return ((char*)haystack);
		else
			haystack++;
	}
	return (NULL);
}
