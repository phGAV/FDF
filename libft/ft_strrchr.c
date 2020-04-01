/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:40:14 by diona             #+#    #+#             */
/*   Updated: 2019/09/20 19:06:44 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = (char*)s;
		s++;
	}
	return (last);
}
