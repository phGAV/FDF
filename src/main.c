/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:57:29 by diona             #+#    #+#             */
/*   Updated: 2020/03/14 00:18:41 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*  kVK_ANSI_Equal                = 0x18,*/
/*  kVK_ANSI_Minus                = 0x1B,*/
/*  kVK_Space                     = 0x31,*/
/*  kVK_Escape                    = 0x35,*/
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

int	key_hook(int keycode, void *mlx)
{
	if (keycode == 0x35)
		exit(0);
	mlx_loop(mlx);
	return (0);
}

int main(void)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "koshka v okoshke");
	mlx_pixel_put(mlx, window, 250, 250, 0x00ffffff);
	mlx_string_put(mlx, window, 200, 200, 0x00ff0000, "^__^");

	mlx_key_hook(window, key_hook, mlx);
	mlx_loop(mlx);
	return (0);
}
