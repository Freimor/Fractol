/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:19 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/26 19:00:16 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*menu(int argc, char **argv)
{
	t_fractol	*fractol;
	int			id;
	char		*name;

	id = 0;
	if (argc != 2)
	{
		ft_putstr("No parameter\nPass the name\n1: mandelbrot\n2: julia\n3: burning_ship\n");
		return (0);
	}
	else
	{
		name = argv[1];
		if ((id = fractol_lib(name)) == -1)
			crash("-- not valid --\nPass the name\n1: mandelbrot\n2: julia\n3: burning_ship\n");
	}
	fractol = fractol_init(id, name);
	return (fractol);
}

int		main(int argc, char **argv)
{
	t_fractol	*fractol;

	if ((fractol = menu(argc, argv)) == NULL)
		return (0);
	else
	{
		draw_fractal(fractol);
		mlx_expose_hook(fractol->win, newdraw, fractol);
		mlx_hook(fractol->win, 2, 0, key_hook_press, fractol);
		mlx_hook(fractol->win, 3, 0, key_hook_release, fractol);
		mlx_hook(fractol->win, 4, 0, mouse_hook, fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
