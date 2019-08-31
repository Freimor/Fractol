/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:10:44 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/29 17:58:07 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_mac.h"

void	movement(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_LEFT)
		fractol->move_x -= fractol->move_mod;
	if (keycode == ARROW_RIGHT)
		fractol->move_x += fractol->move_mod;
	if (keycode == ARROW_DOWN)
		fractol->move_y -= fractol->move_mod;
	if (keycode == ARROW_UP)
		fractol->move_y += fractol->move_mod;
	draw_fractal(fractol);
}

void	zoom(int keycode, t_fractol *fractol)
{
	if (keycode == MOUSE_SCROLL_DOWN || keycode == NUM_PAD_PLUS)
		fractol->zoom *= fractol->zoom_mod;
	if (keycode == MOUSE_SCROLL_UP || keycode == NUM_PAD_MINUS)
		fractol->zoom /= fractol->zoom_mod;
	draw_fractal(fractol);
}

void	mods_one(int keycode, t_fractol *fractol)
{
	if (keycode == MAIN_PAD_MINUS && fractol->zoom_mod > 1.3)
		fractol->zoom_mod *= 0.8;
	if (keycode == MAIN_PAD_PLUS && fractol->zoom_mod < 20)
		fractol->zoom_mod *= 1.2;
	if (keycode == MAIN_PAD_C_BRAC_L && fractol->move_mod > 11)
		fractol->move_mod -= 10;
	if (keycode == MAIN_PAD_C_BRAC_R && fractol->move_mod < 100)
		fractol->move_mod += 10;
	if (keycode == MAIN_PAD_D)
		setup_default(fractol);
	draw_fractal(fractol);
}

void	mods_two(int keycode, t_fractol *fractol)
{
	if (keycode == MAIN_PAD_Z && fractol->max_it < 201)
		fractol->max_it += 10;
	if (keycode == MAIN_PAD_X && fractol->max_it > 11)
		fractol->max_it -= 10;
	if (keycode == MAIN_PAD_COMMA)
	{
		if (fractol->id == 0)
			fractol->id = 4;
		else
			fractol->id -= 1;
		setup_default(fractol);
	}
	if (keycode == MAIN_PAD_DOT)
	{
		if (fractol->id == 4)
			fractol->id = 0;
		else
			fractol->id += 1;
		setup_default(fractol);
	}
	draw_fractal(fractol);
}

int		julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->k.r = 4 * ((double)x / XMAX - 0.5);
	fractol->k.i = 4 * ((double)(YMAX - y) / YMAX - 0.5);
	draw_fractal(fractol);
	return (0);
}
