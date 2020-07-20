/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:08:34 by diona             #+#    #+#             */
/*   Updated: 2019/09/12 23:10:04 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			bn;
	int			d;
	long int	lnb;

	d = 1;
	lnb = n;
	if (lnb < 0)
	{
		lnb = lnb * -1;
		ft_putchar_fd('-', fd);
	}
	bn = lnb;
	while (bn / 10 != 0)
	{
		bn = bn / 10;
		d = d * 10;
	}
	while (d != 0)
	{
		ft_putchar_fd('0' + lnb / d, fd);
		lnb = lnb - (lnb / d) * d;
		d = d / 10;
	}
}
