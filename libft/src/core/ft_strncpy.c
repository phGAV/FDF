/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 00:07:11 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 14:03:57 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d;

	d = dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (len--)
	{
		if (*src != '\0')
			*d++ = *src++;
		else
			*d++ = '\0';
	}
	return (dst);
}
