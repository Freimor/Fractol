/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:10:44 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/24 18:43:33 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_mac.h"

int		key_hook_press(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == MAIN_PAD_ESC)
	{
		free(fractol);
		exit(0);
	}
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
			|| keycode == ARROW_DOWN || keycode == ARROW_UP)
		movement(keycode, fractol);
	else if (keycode == NUM_PAD_MINUS || keycode == NUM_PAD_PLUS)
		zoom(keycode, fractol);
	else if (keycode == 18 || keycode == 19 || keycode == 20)
		color_change(keycode, fractol);
	else if (keycode == MAIN_PAD_I)
		hide_help(fractol);
	return (0);
}

int		mouse_hook(int keycode, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_SCROLL_UP)
		zoom(keycode, fractol);
	return (0);
}

int		key_hook_release(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	movement(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_LEFT)
		fractol->move_x += 10;
	if (keycode == ARROW_RIGHT)
		fractol->move_x -= 10;
	if (keycode == ARROW_DOWN)
		fractol->move_y += 10;
	if (keycode == ARROW_UP)
		fractol->move_y -= 10;
	draw_fractal(fractol);
}

void	zoom(int keycode, t_fractol *fractol)
{
	if (keycode == MOUSE_SCROLL_DOWN || keycode == NUM_PAD_PLUS)
		fractol->zoom *= 1.2;
	if (keycode == MOUSE_SCROLL_UP || keycode == NUM_PAD_MINUS)
		fractol->zoom *= 0.8;
	draw_fractal(fractol);
}

int		newdraw(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->win);
	if (fractol->id == 0)
		mandelbrot(fractol);
	if (fractol->id == 1)
		julia(fractol);
	return (0);
}

int		julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->k = init_complex(
		4 * ((double)x / XMAX - 0.5),
		4 * ((double)(YMAX - y) / YMAX - 0.5));
	draw_fractal(fractol);
	return (0);
}

void	hide_help(t_fractol *fractol)
{
	if (fractol->flag_hide == 0)
	{
		fractol->flag_hide = 1;
		fractol->x_size_fractol = XMAX;
		fractol->x_size_help = 0;
	}
	else if (fractol->flag_hide == 1)
	{
		fractol->flag_hide = 0;
		fractol->x_size_fractol = XMAX * 0.8;
		fractol->x_size_help = XMAX - fractol->x_size_fractol;
	}
	draw_fractal(fractol);
}
