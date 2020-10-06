/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:05:46 by diona             #+#    #+#             */
/*   Updated: 2020/07/25 18:41:01 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "fdf.h"

# define KEYBOARD_MAX 127

# define OFFSET_STEP		10
# define ANGLE_STEP_ORTO	1.57
# define ANGLE_STEP			0.02

# define MAX_ZOOM			400
# define MIN_ZOOM			4

# define ESC				0x35

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define C					8
# define I					34
# define M					46
# define P					35
# define KEY_0				29
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define PLUS				24
# define MINUS				27

# define KEY_PRESS			02
# define KEY_RELEASE		03
# define BUTTON_PRESS		04
# define BUTTON_RELEASE		05
# define MOTION_NOTIFY		06
# define DESTROY_NOTIFY		17

typedef void	(*t_shortcut)(t_fdf *, int);

void	move_side(t_fdf *fdf, int keycode);
void	move_up(t_fdf *fdf, int keycode);
void	change_angle_x(t_fdf *fdf, int keycode);
void	change_angle_y(t_fdf *fdf, int keycode);
void	change_angle_z(t_fdf *fdf, int keycode);
void	change_projection(t_fdf *fdf, int keycode);
void	change_colors(t_fdf *fdf, int keycode);
void	change_blur(t_fdf *fdf, int keycode);
void	flatten(t_fdf *fdf, int keycode);

int		mouse_pressed(int button, int x, int y, t_fdf *fdf);
int		mouse_released(int button, int x, int y, t_fdf *fdf);
int		mouse_move(int x, int y, t_fdf *fdf);

int		close_hook(t_fdf *fdf, int keycode);

#endif
