/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <diona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:55:03 by diona             #+#    #+#             */
/*   Updated: 2020/07/10 01:22:15 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# include "libft.h"
# include "errors.h"

# define WIN_HEIGHT	1000
# define WIN_WIDTH	1250
# define MENU_WIDTH	250

# define WHITE		0x00FFFFFF
# define PINK		0x00FF3DEA
# define TURQUOISE	0x0000FFEC
# define BG_BLUR	0xe0000000
# define BG_SOLID	0x00000000
# define BG_MENU	0x00131313

typedef struct {
	bool			hold;
	bool			hold_rmb;
	int				x;
	int				y;
	int				prev_x;
	int				prev_y;
}	t_mouse;

typedef enum {
	ISO,
	PARALLEL
}	t_projection;

typedef struct		s_point {
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct {
	ssize_t			width;
	ssize_t			height;
	t_vec			*vertex;
	int				max_z;
	int				min_z;
	int				lo_color;
	int				hi_color;
	int				bg_color;
}	t_map;

typedef struct {
	t_projection	projection;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	int				ratio_z;
	int				zoom;
	int				offset_x;
	int				offset_y;
}	t_camera;

typedef struct		s_fdf {
	t_camera		*camera;
	t_mouse			*mouse;
	t_map			*map;
	void			*mlx;
	void			*window;
	void			*image;
	int				*img_ptr;
	void			*menu;
	int				*menu_ptr;
	int				bpp;
	int				line_size;
	int				endian;
}					t_fdf;

void				set_background(int *img_ptr, int color, size_t size);
void				draw_line(t_point start, t_point end, t_fdf *fdf);
void				exit_err(char *err_msg);
void				read_map(int fd, t_map *map);
void				draw_map(t_fdf *fdf);
void				draw_menu(t_fdf *fdf);
int					find_vertex_color(t_map *map,
						int max, int min, int current);
void				events_control(t_fdf *fdf);
void				camera_init(t_camera *camera, t_map *map);
t_point				projection(t_point p, t_fdf *fdf);
int					find_color(t_point *current, t_point *begin, t_point *end);
int					get_opacity(int color, double opacity);

#endif
