/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:45:40 by diona             #+#    #+#             */
/*   Updated: 2020/07/05 17:06:26 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

#include "fdf.h"

void	exit_err(char *err_msg)
{
	if (errno != 0)
		perror(err_msg);
	else
		ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
