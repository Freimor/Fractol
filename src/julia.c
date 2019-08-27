/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:06:39 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/27 16:35:08 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *st)
{
	st->x = 0;
	while (st->x < st->x_size_fractol)
	{
		st->c.r = (st->min.r + st->x + st->move_x) * st->factor.r / st->zoom;
		st->y = 0;
		while (st->y < YMAX)
		{
			st->c.i = (st->max.i - st->y + st->move_y) * st->factor.i / st->zoom;
			st->z = init_complex(st->c.r, st->c.i);
			st->z.i = st->c.i;
			st->z.r = st->c.r;
			st->it = 0;
			while ((st->z.r * st->z.r + st->z.i * st->z.i < 4)
			&& (st->it < ITERATION))
			{
				st->z = init_complex(
				pow(st->z.r, 2.0) - pow(st->z.i, 2.0) + st->k.r,
				2.0 * st->z.r * st->z.i + st->k.i);
				st->it++;
			}
			//putpixel(st, st->x, st->y, set_color(st));
			put_pixel_to_addr(st, st->x, st->y, set_color(st)); //отредактировать и убрать init_complex
			st->y++;
		}
		st->x++;
	}
}
