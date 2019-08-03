/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:41 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/03 17:46:25 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_COUNT 300
# define YMAX 1080
# define XMAX 1920

# define ZOOM 600
# define DEPTH 1000     //  чем выше этотпоказатель, тем "глубже" получается картинка
# define XC 0
# define YC -350


# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED   0xe74c3c



# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_fractol
{
	char	*name;
	void	*ptr;
	void	*win;
	float	xside;
	float	tempx;
	float	yside;
	float	left;
	float	top;
	float	xscale;
	float	yscale;
	float	cx;
	float	cy;
	float	zx;
	float	zy;
}				t_fractol;

void	fractal(float left, float top, float xside, float yside, void *ptr, void *win);
int		key_hook(int keycode, void *param);
int		get_hook(t_fractol *fractol);
void	fractol_test(t_fractol *fractol);


#endif