/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:20:43 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/29 17:51:39 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractol_init(int id, char *name)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		crash("Fractol malloc crash");
	if (!(fractol->mlx = mlx_init()))
		crash("Mlx init crash");
	if (!(fractol->win = mlx_new_window(fractol->mlx, XMAX, YMAX, name)))
		crash("Mlx window create crash");
	if (!(fractol->image = mlx_new_image(fractol->mlx, XMAX, YMAX)))
		crash("New image init crash");
	if (!(fractol->data_addr = mlx_get_data_addr(fractol->image,
	&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian)))
		crash("Getting data addr for image crash");
	fractol->id = id;
	fractol->flag_first = 1;
	setup_default(fractol);
	return (fractol);
}

void		setup_default(t_fractol *fractol)
{
	if (fractol->flag_first == 1)
	{
		fractol->preset = 1;
		fractol->flag_first = 0;
	}
	fractol->min.r = -2.0;
	fractol->min.i = -2.0;
	fractol->max.r = 2.0;
	fractol->max.i = fractol->min.i + (fractol->max.r - fractol->min.r)
	* YMAX / XMAX;
	fractol->k.r = -0.4;
	fractol->k.i = 0.6;
	fractol->factor.r = (fractol->max.r - fractol->min.r) / (XMAX - 1);
	fractol->factor.i = (fractol->max.i - fractol->min.i) / (YMAX - 1);
	fractol->move_x = -(XMAX / 2);
	fractol->move_y = YMAX / 2;
	fractol->zoom = 1;
	fractol->x_size_fractol = XMAX * 0.8;
	fractol->flag_hide = 0;
	fractol->move_mod = 12;
	fractol->zoom_mod = 1.2;
	fractol->max_it = 50;
}
