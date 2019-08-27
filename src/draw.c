/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:13:49 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/26 18:58:03 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->win);
	if (fractol->id == 0)
		mandelbrot(fractol);
	if (fractol->id == 1)
		julia(fractol);
	if (fractol->id == 2)
		burning_ship(fractol);
	draw_help(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
}

int		set_color(t_fractol *fractol)
{
	double	t;

	t = (double)fractol->it / ITERATION;
	if (fractol->preset == 1)
	{
		fractol->r = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 194);
		fractol->g = (int)(9 * (1 - t) * pow(t, 3) * 54);
		fractol->b = (int)(8.5 * pow((1 - t), 3) * t * 22);
	}
	if (fractol->preset == 2)
	{
		fractol->r = (int)(255 * t * 3);
		fractol->g = (int)(189 * t * t);
		fractol->b = (int)(67 - (1 - t) * (1 - t));
	}
	return ((fractol->r << 16) | (fractol->g << 8) | (fractol->b));
}

void	putpixel(t_fractol *fractol, int x, int y, int color)
{
	mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
	return ;
}

void	color_change(int keycode, t_fractol *fractol)
{
	if (keycode == 18)
	{
		fractol->preset = 1;
	}
	if (keycode == 19)
	{
		fractol->preset = 2;
	}
	if (keycode == 20)
	{
		fractol->preset = 3;
	}
	draw_fractal(fractol);
}
