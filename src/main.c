/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:19 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/04 17:45:05 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractol_init(int id, char *name)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	fractol->ptr = mlx_init();
	fractol->win = mlx_new_window(fractol->ptr, XMAX, YMAX, name);
	fractol->id = id;
	fractol->move_x = 0;
	fractol->move_y = -350;
	fractol->zoom = 600;
	return (fractol);
}

t_fractol	*menu(int argc, char **argv)
{
	t_fractol	*fractol;
	int			id;
	char		*name;

	if (argc != 2)
	{
		ft_putstr("Error\nPass the name\n1: mandelbrot\n");
		return (0);
	}
	else
	{
		name = argv[1];
		if (ft_strequ(name, "mandelbrot") != 0)
			id = 1;
		else
		{
			ft_putstr("-- not valid --\n 1: mandelbrot\n");
			return (0);
		}
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
		mandelbrot(fractol);
		mlx_expose_hook(fractol->win, newdraw, fractol);
		mlx_hook(fractol->win, 2, 0, key_hook_press, fractol);
		mlx_hook(fractol->win, 3, 0, key_hook_release, fractol);
		mlx_loop(fractol->ptr);
	}
	return (0);
}
