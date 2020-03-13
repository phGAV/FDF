/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:31:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/17 19:33:42 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *p1, const void *p2, size_t n)
{
	while (n--)
		if (*(unsigned char *)p1++ != *(unsigned char *)p2++)
			return (*(unsigned char *)--p1 - *(unsigned char *)--p2);
	return (0);
}
