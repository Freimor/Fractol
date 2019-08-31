/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:13:38 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/29 16:28:39 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	text_help(t_fractol *f, int color)
{
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	50, color, "Controls");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	70, color, "Move: Arrows");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	90, color, "Move modif: { }");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	110, color, "Zoom: Scroll and numpad + -");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	130, color, "Zoom modif: main pad + -");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	150, color, "Change fractols: > <");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	170, color, "Change color preset: Main pad 1 2 3");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	190, color, "Hide unhide help: I");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	210, color, "Setup default: D");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	230, color, "Change iterations: Z X");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	250, color, "Exit: Esc");
}

void	hide_help(t_fractol *fractol)
{
	if (fractol->flag_hide == 0)
	{
		fractol->flag_hide = 1;
		fractol->x_size_fractol = XMAX;
	}
	else if (fractol->flag_hide == 1)
	{
		fractol->flag_hide = 0;
		fractol->x_size_fractol = XMAX * 0.8;
	}
	draw_fractal(fractol);
}
