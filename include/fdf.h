/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:55:03 by diona             #+#    #+#             */
/*   Updated: 2020/03/16 01:03:07 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "libft.h"

# define WIN_HEIGHT 500
# define WIN_WIDTH 700

# define ESC 0x35
/*  kVK_ANSI_Equal                = 0x18,*/
/*  kVK_ANSI_Minus                = 0x1B,*/
/*  kVK_Space                     = 0x31,*/
/*  kVK_Command                   = 0x37,*/
/*  kVK_Shift                     = 0x38,*/
/*  kVK_CapsLock                  = 0x39,*/
/*  kVK_Option                    = 0x3A,*/
/*  kVK_Control                   = 0x3B,*/
/*  kVK_RightShift                = 0x3C,*/
/*  kVK_RightOption               = 0x3D,*/
/*  kVK_RightControl              = 0x3E,*/
/*  kVK_Function                  = 0x3F,*/
/*  kVK_LeftArrow                 = 0x7B,*/
/*  kVK_RightArrow                = 0x7C,*/
/*  kVK_DownArrow                 = 0x7D,*/
/*  kVK_UpArrow                   = 0x7E*/

# define WHITE 0x00FFFFFF
# define PINK 0x00FF3DEA
# define TURQUOISE 0x0000FFEC

typedef struct {
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

#endif
