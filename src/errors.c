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

#include "fdf.h"
#include <sys/errno.h>

void	exit_err(char *err_msg)
{
	if (errno != 0)
		perror(err_msg);
	else
	{
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
