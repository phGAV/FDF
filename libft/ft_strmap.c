/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:01:10 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/25 07:41:47 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *dst;
	char *p;

	if (!s || !*s || !f)
		return (NULL);
	if ((dst = ft_strnew(ft_strlen(s))))
	{
		p = dst;
		while (*s)
			*p++ = f(*s++);
	}
	return (dst);
}
