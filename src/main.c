/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:06:19 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/31 17:07:25 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_names(void)
{
	ft_putstr("1: mandelbrot\n");
	ft_putstr("2: julia\n");
	ft_putstr("3: burning_ship\n");
	ft_putstr("4: triangle\n");
	ft_putstr("5: buffalo\n");
}

t_fractol	*menu(int argc, char **argv)
{
	t_fractol	*fractol;
	int			id;
	char		*name;

	id = 0;
	if (argc != 2)
	{
		ft_putstr("No parameter\nPass the name\n");
		print_names();
		return (0);
	}
	else
	{
		name = argv[1];
		if ((id = fractol_lib(name)) == -1)
		{
			ft_putstr("-- not valid --\nPass the name\n");
			print_names();
			return (0);
		}
	}
	fractol = fractol_init(id, name);
	return (fractol);
}

int			main(int argc, char **argv)
{
	t_fractol	*fractol;

	if ((fractol = menu(argc, argv)) == NULL)
		return (0);
	else
	{
		draw_fractal(fractol);
		mlx_expose_hook(fractol->win, draw_fractal, fractol);
		mlx_hook(fractol->win, 2, 0, key_hook_press, fractol);
		mlx_hook(fractol->win, 4, 0, mouse_hook, fractol);
		mlx_hook(fractol->win, 6, 0, julia_motion, fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
