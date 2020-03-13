/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 04:03:37 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/24 22:33:16 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mommys_little_helper(long n, int fd)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
		mommys_little_helper(n / 10, fd);
	ft_putchar_fd(n % 10 | 060, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	mommys_little_helper(n, fd);
}
