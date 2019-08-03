/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:19 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/03 17:02:26 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol	fractol;
    // setting the left, top, xside and yside 
    // for the screen and image to be displayed 
    fractol.left = 0; //-1.75
    fractol.top = 0; //-0.25
    fractol.xside = 120; //0.25
    fractol.yside = 120; //0.45
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		fractol.name = argv[1];
		if (ft_strequ(fractol.name, "fractol") == 0)
		{
			ft_putstr("-- not valid --\n 1: Fractol\n");
			return (0);
		}
		fractol.ptr = mlx_init();
		fractol.win = mlx_new_window(fractol.ptr, XMAX, YMAX, fractol.name);
		//fractal(fractol.left, fractol.top, fractol.xside, fractol.yside, fractol.ptr, fractol.win);
		fractol_test(&fractol);
		mlx_expose_hook(fractol.win, get_hook, &fractol);
		mlx_hook(fractol.win, 2, 0, key_hook, &fractol);
		mlx_loop(fractol.ptr);
	}
	return (0);
}
