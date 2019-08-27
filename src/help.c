/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:13:38 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/26 18:06:13 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		text_help(t_fractol *f)
{
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	50, HELP_COLOR_FONT, "Controls");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	70, HELP_COLOR_FONT, "Move: Arrows");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	90, HELP_COLOR_FONT, "Zoom: Scroll and numpad + -");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	110, HELP_COLOR_FONT, "Change color preset: Main pad 1 2 3");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	130, HELP_COLOR_FONT, "Hide unhide help: I");
	mlx_string_put(f->mlx, f->win, f->x_size_fractol + 20,
	150, HELP_COLOR_FONT, "Exit: Esc");
}

void	draw_help(t_fractol *f)
{
	int		x;
	int		y;

	if (f->flag_hide == 0)
	{
		x = f->x_size_fractol;
		while (x < XMAX)
		{
			y = 0;
			while (y < YMAX)
			{
				//putpixel(f, x, y, BLACK);
				put_pixel_to_addr(f, x, y, BLACK);
				y++;
			}
			x++;
		}
		text_help(f);
	}
}
