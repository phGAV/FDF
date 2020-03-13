/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:42:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/24 19:29:54 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank_l(int c)
{
	return (ft_isblank(c) || \
			(unsigned)c == '\n' || \
			(unsigned)c == '\v' || \
			(unsigned)c == '\f' || \
			(unsigned)c == '\r');
}

int			ft_atoi(const char *s)
{
	int n;
	int neg;

	n = 0;
	while (ft_isblank_l(*s))
		s++;
	neg = ((*s == '+' || *s == '-') && *s++ == '-') ? 1 : 0;
	while (ft_isdigit(*s))
		n = (n << 3) + (n << 1) + (*s++ & ~060);
	return (neg ? -n : n);
}
