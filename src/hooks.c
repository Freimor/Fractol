/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:10:44 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/04 17:31:51 by sskinner         ###   ########.fr       */
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
		fractol->move_x -= 1;
	if (keycode == ARROW_RIGHT)
		fractol->move_x += 1;
	if (keycode == ARROW_DOWN)
		fractol->move_y -= 1;
	if (keycode == ARROW_UP)
		fractol->move_y += 1;
	newdraw(fractol);
}

void	zoom(int keycode, t_fractol *fractol)
{
	if (keycode == NUM_PAD_MINUS)
		fractol->zoom -= 1.0;
	if (keycode == NUM_PAD_PLUS)
		fractol->zoom += 1.0;
	newdraw(fractol);
}

int		newdraw(t_fractol *fractol)
{
	mlx_clear_window(fractol->ptr, fractol->win);
	mandelbrot(fractol);
	return (0);
}

/* void	ft_scal_zoom2(int keycode, t_fdf *fdf)
{
	if (keycode == 125)
	{
		if (fdf->scaly <= 0)
			fdf->scaly = 0;
		else
			fdf->scaly -= 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
	else if (keycode == 126)
	{
		if (fdf->scaly >= HEIGHTH)
			fdf->scaly = HEIGHTH;
		else
			fdf->scaly += 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
}


void	ft_scal_zoom1(int keycode, t_fdf *fdf)
{
	if (keycode == 124)
	{
		if (fdf->scalx <= 0)
			fdf->scalx = 0;
		else
			fdf->scalx -= 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
	else if (keycode == 123)
	{
		if (fdf->scalx >= WIDTH)
			fdf->scalx = WIDTH;
		else
			fdf->scalx += 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
}

void	ft_iso(int keycode, t_fdf *fdf)
{
	if (keycode == 83)
	{
		fdf->flag_iso = 0;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
	else if (keycode == 84)
	{
		fdf->flag_iso = 1;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
}*/
