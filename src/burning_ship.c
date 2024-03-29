/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:32:37 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/29 16:23:48 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	burning_ship(t_fractol *st)
{
	st->x = 0;
	while (st->x < st->x_size_fractol)
	{
		st->c.r = (st->min.r + st->x + st->move_x) * st->factor.r / st->zoom;
		st->y = 0;
		while (st->y < YMAX)
		{
			st->c.i = (st->max.i - st->y + st->move_y)
			* st->factor.i / st->zoom;
			st->z.i = 0.0;
			st->z.r = 0.0;
			st->it = 0;
			while ((st->z.r * st->z.r + st->z.i * st->z.i < 7)
			&& (st->it < st->max_it))
			{
				st->temp = st->z.r * st->z.r - st->z.i * st->z.i + st->c.r;
				st->z.i = fabs(2 * st->z.r * st->z.r) + st->c.i;
				st->z.r = fabs(st->temp);
				st->it++;
			}
			put_pixel_to_addr(st, st->x, st->y, set_color(st));
			st->y++;
		}
		st->x++;
	}
}
