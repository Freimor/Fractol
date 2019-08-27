/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:47:23 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/26 19:00:22 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	crash(char *error)
{
	ft_putendl(error);
	exit(0);
}

t_complex	init_complex(float r, float i)
{
	t_complex complex;

	complex.r = r;
	complex.i = i;
	return (complex);
}

void		put_pixel_to_addr(t_fractol *fractol, int x, int y, int color)
{
	int i;

	i = (x * fractol->bits_per_pixel / 8) + (y * fractol->size_line);
	fractol->data_addr[i] = color;
	fractol->data_addr[++i] = color >> 8;
	fractol->data_addr[++i] = color >> 16;
	fractol->data_addr[++i] = 0;
}

int			fractol_lib(char *name)
{
	char	**lib;
	int		i;

	i = 0;
	lib[0] = "mandelbrot";
	lib[1] = "julia";
	lib[2] = "burning_ship";
	lib[3] = NULL;
	while (i < 3)
	{
		if (ft_strequ(lib[i], name))
			return (i);
		else if (lib[i] == NULL)
			break ;
		i++;
	}
	return (-1);
}

int		alpha_mod_background(int background, int color, float alpha)
{
	int red;
	int green;
	int blue;

	red = (((color >> 16 & 0xFF) + (background >> 16 & 0xFF)) / 2) * alpha;
	green = (((color >> 8 & 0xFF) + (background >> 8 & 0xFF)) / 2) * alpha;
	blue = (((color & 0xFF) + (background & 0xFF)) / 2) * alpha;
	return ((red << 16) | (green << 8) | blue);
}
