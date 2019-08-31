/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:13:49 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/29 17:41:36 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_fractal(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->win);
	if (fractol->id == 0)
		mandelbrot(fractol);
	if (fractol->id == 1)
		julia(fractol);
	if (fractol->id == 2)
		burning_ship(fractol);
	if (fractol->id == 3)
		triangle(fractol);
	if (fractol->id == 4)
		buffalo(fractol);
	draw_rectangle(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
	text_help(fractol, WHITE);
	return (0);
}

void	color_change(int keycode, t_fractol *fractol)
{
	if (keycode == 18)
		fractol->preset = 1;
	if (keycode == 19)
		fractol->preset = 2;
	if (keycode == 20)
		fractol->preset = 3;
	draw_fractal(fractol);
}

int		set_color(t_fractol *fractol)
{
	double	t;

	t = (double)fractol->it / fractol->max_it;
	if (fractol->preset == 1)
	{
		fractol->r = (int)(15 * (1 - t) * (1 - t) * t * t * 194);
		fractol->g = (int)(9 * (1 - t) * t * t * t * 54);
		fractol->b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 22);
	}
	if (fractol->preset == 2)
	{
		fractol->r = (int)(255 * t * 3);
		fractol->g = (int)(183 * t * t);
		fractol->b = (int)(90 - (1 - t) * (1 - t));
	}
	if (fractol->preset == 3)
	{
		fractol->r = (int)(150 * t * (1 - t));
		fractol->g = (int)(150 * t * t * fractol->it);
		fractol->b = (int)(150 * 3 * t);
		if (t > 0.5)
			fractol->r = (int)(15 * (1 - t) * (1 - t) * t * 194);
	}
	return ((fractol->r << 16) | (fractol->g << 8) | (fractol->b));
}
