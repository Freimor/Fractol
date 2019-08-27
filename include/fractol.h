/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:41 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/26 18:56:05 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_COUNT 300
# define YMAX 1080
# define XMAX 1920

# define ZOOM 600
# define ITERATION 50     //  чем выше этотпоказатель, тем "глубже" получается картинка
# define HELP_COLOR_BACK 0x222f3e
# define HELP_COLOR_FONT 0x8395a7

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED   0xe74c3c

///сделать хуки на передвижение и скалирование
///запихать в image

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

typedef struct s_fractol
{
	int		id;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data_addr;
	void	*image;
	
	float	move_x;
	float	move_y;
	float	zoom;

	int		x_size_fractol;
	int		x_size_help;

	t_complex	z;
	t_complex	c;
	t_complex	k;
	t_complex	min;
	t_complex	max;
	t_complex	factor;

	int		x;
	int		y;
	int		it;
	
	int		r;
	int		g;
	int		b;
	int		flag_hide;
	int		preset;
	float	temp;
}				t_fractol;

t_fractol	*fractol_init(int id, char *name);
t_fractol	*menu(int argc, char **argv);
void		movement(int keycode, t_fractol *fractol);
void		zoom(int keycode, t_fractol *fractol);
int			newdraw(t_fractol *fractol);
void		putpixel (t_fractol *fractol, int x, int y, int color);
t_complex	init_complex(float r, float i);



//init
t_fractol	*fractol_init(int id, char *name);
void		setup_default(t_fractol *fractol);
t_complex	init_complex(float r, float i);

//draw
void		mandelbrot(t_fractol *mand);
void		julia(t_fractol *st);
void		burning_ship(t_fractol *st);
void		draw_help(t_fractol *fractol);
void		draw_fractal(t_fractol *fractol);
void		put_pixel_to_addr(t_fractol *fractol, int x, int y, int color);


//color
int			set_color(t_fractol *fractol);
int			alpha_mod_background(int background, int color, float alpha);


//utils
void		crash(char *error);
void		put_pixel_to_addr(t_fractol *fractol, int x, int y, int color);
int			fractol_lib(char *name);
void		color_change(int keycode, t_fractol *fractol);
void		hide_help(t_fractol *fractol);

//hooks
int			mouse_hook(int keycode,int x, int y, void *param);
int			key_hook_press(int keycode, void *param);
int			key_hook_release(int keycode, void *param);
int			julia_motion(int x, int y, t_fractol *fractol);


#endif
