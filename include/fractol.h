/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:41 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/04 17:42:23 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_COUNT 300
# define YMAX 1080
# define XMAX 1920

# define ZOOM 600
# define ITERATION 300     //  чем выше этотпоказатель, тем "глубже" получается картинка
# define XC 0
# define YC -350


# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED   0xe74c3c

///сделать хуки на передвижение и скалирование
///запихать в image

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_fractol
{
	int		id;
	void	*ptr;
	void	*win;

	int		move_x;
	int		move_y;

	float	zoom;
	
	float	z_r;
	float	z_i;
	float	c_r;
	float	c_i;

}				t_fractol;

t_fractol	*fractol_init(int id, char *name);
t_fractol	*menu(int argc, char **argv);
int			key_hook_press(int keycode, void *param);
int			key_hook_release(int keycode, void *param);
void		movement(int keycode, t_fractol *fractol);
void		zoom(int keycode, t_fractol *fractol);
int			newdraw(t_fractol *fractol);
void		mandelbrot(t_fractol *mand);



#endif
