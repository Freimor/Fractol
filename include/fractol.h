/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:41 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/31 16:54:11 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define YMAX 1080
# define XMAX 1920

# define HELP_COLOR_BACK 0x222f3e
# define HELP_COLOR_FONT 0x8395a7

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED   0xe74c3c

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_complex
{
	float	r;
	float	i;
}				t_complex;

typedef struct	s_fractol
{
	int			id;
	void		*mlx;
	void		*win;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*data_addr;
	void		*image;
	float		move_x;
	float		move_y;
	float		move_mod;
	float		zoom;
	float		zoom_mod;
	int			x_size_fractol;
	t_complex	z;
	t_complex	c;
	t_complex	k;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			x;
	int			y;
	int			it;
	int			max_it;
	int			r;
	int			g;
	int			b;
	int			flag_hide;
	int			flag_first;
	int			preset;
	float		temp;
}				t_fractol;

t_fractol		*fractol_init(int id, char *name);
t_fractol		*menu(int argc, char **argv);
void			setup_default(t_fractol *fractol);
void			mandelbrot(t_fractol *mand);
void			buffalo(t_fractol *mand);
void			julia(t_fractol *st);
void			burning_ship(t_fractol *st);
void			triangle(t_fractol *st);
void			draw_rectangle(t_fractol *fractol);
int				draw_fractal(t_fractol *fractol);
void			put_pixel_to_addr(t_fractol *fractol, int x, int y, int color);
void			text_help(t_fractol *f, int color);
int				set_color(t_fractol *fractol);
void			crash(char *error);
void			put_pixel_to_addr(t_fractol *fractol, int x, int y, int color);
int				fractol_lib(char *name);
void			color_change(int keycode, t_fractol *fractol);
void			hide_help(t_fractol *fractol);
int				mouse_hook(int keycode, int x, int y, void *param);
int				key_hook_press(int keycode, void *param);
int				key_hook_release(int keycode, void *param);
int				julia_motion(int x, int y, t_fractol *fractol);
void			mods_one(int keycode, t_fractol *fractol);
void			movement(int keycode, t_fractol *fractol);
void			zoom(int keycode, t_fractol *fractol);
void			mods_two(int keycode, t_fractol *fractol);
void			fractol_memfree(t_fractol *fractol);

#endif
