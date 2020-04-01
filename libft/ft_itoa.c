/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 00:07:23 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 21:50:01 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_digit(int n)
{
	int d;

	d = 1;
	if (n < 0)
		d++;
	while (n /= 10)
		d++;
	return (d);
}

char		*ft_itoa(int n)
{
	unsigned int	ln;
	int				i;
	char			*s;

	i = ft_digit(n);
	s = ft_strnew(i);
	if (!s)
		return (NULL);
	ln = n;
	if (n < 0)
		ln = n * -1;
	s[--i] = ln % 10 + '0';
	while (ln /= 10)
		s[--i] = ln % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
