/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 03:59:53 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/17 23:57:35 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *p;

	p = dst;
	while (*p)
		p++;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (dst);
}
