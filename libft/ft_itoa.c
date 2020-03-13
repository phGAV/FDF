/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:33:12 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/16 09:02:35 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digits(int n)
{
	int ret;

	ret = 1;
	if (n < 0)
		ret++;
	while (n /= 10)
		ret++;
	return (ret);
}

char			*ft_itoa(int n)
{
	char		*s;
	char		*p;
	int			d;
	unsigned	num;

	d = ft_digits(n);
	if (!(s = ft_strnew(d)))
		return (NULL);
	p = s;
	if (n < 0)
		*p = '-';
	num = n < 0 ? 0 - n : n;
	p += d;
	while ((*--p = num % 10 | 060) && (num /= 10))
		continue ;
	return (s);
}
