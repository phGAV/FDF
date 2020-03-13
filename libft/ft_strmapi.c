/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:35:27 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/25 07:41:50 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	char			*p;
	unsigned int	i;

	if (!s || !*s || !f)
		return (NULL);
	if ((dst = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		p = dst;
		while (*s)
			*p++ = f(i++, *s++);
	}
	return (dst);
}
