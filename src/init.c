/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:20:43 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/26 18:15:02 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractol_init(int id, char *name)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		crash("Fractol struct memory error");
	if (!(fractol->mlx = mlx_init()))
		crash("Fractol mlx error");
	if (!(fractol->win = mlx_new_window(fractol->mlx, XMAX, YMAX, name)))
		crash("Fractol window initialization error");
	if (!(fractol->image = mlx_new_image(fractol->mlx, XMAX, YMAX)))
		crash("Create image error");
	if (!(fractol->data_addr = mlx_get_data_addr(fractol->image,
	&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian)))
		crash("Fractol image address error");
	fractol->id = id;
	if (id == 1)
		mlx_hook(fractol->win, 6, 0, julia_motion, fractol);
	setup_default(fractol);
	return (fractol);
}

void		setup_default(t_fractol *fractol)
{
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.r = 2.0;
	fractol->max.i = fractol->min.i + (fractol->max.r - fractol->min.r)
	* YMAX / XMAX;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->factor = init_complex(
		(fractol->max.r - fractol->min.r) / (XMAX - 1),
		(fractol->max.i - fractol->min.i) / (YMAX - 1));
	fractol->move_x = -(XMAX / 2);
	fractol->move_y = YMAX / 2;
	fractol->zoom = 1;

	fractol->x_size_fractol = XMAX * 0.8;
	fractol->x_size_help = XMAX - fractol->x_size_fractol;

	fractol->preset = 1;
	fractol->flag_hide = 0;
}

