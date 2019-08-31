/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:47:23 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/31 16:59:40 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	crash(char *error)
{
	ft_putendl(error);
	exit(0);
}

void	put_pixel_to_addr(t_fractol *fractol, int x, int y, int color)
{
	int i;

	i = (x * fractol->bits_per_pixel / 8) + (y * fractol->size_line);
	fractol->data_addr[i] = color;
	fractol->data_addr[++i] = color >> 8;
	fractol->data_addr[++i] = color >> 16;
	fractol->data_addr[++i] = 0;
}

int		fractol_lib(char *name)
{
	char	*lib[6];
	int		i;

	i = 0;
	lib[0] = "mandelbrot";
	lib[1] = "julia";
	lib[2] = "burning_ship";
	lib[3] = "triangle";
	lib[4] = "buffalo";
	lib[5] = NULL;
	while (i < 5)
	{
		if (ft_strequ(lib[i], name))
			return (i);
		else if (lib[i] == NULL)
			break ;
		i++;
	}
	return (-1);
}

void	draw_rectangle(t_fractol *f)
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
				put_pixel_to_addr(f, x, y, BLACK);
				y++;
			}
			x++;
		}
	}
}
