/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:10:44 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/01 18:10:45 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == 53)
		exit(0);
	/* else if (keycode == 78 || keycode == 69)
		ft_step_zoom(keycode, fractol);
	else if (keycode == 123 || keycode == 124)
		ft_scal_zoom1(keycode, fractol);
	else if (keycode == 125 || keycode == 126)
		ft_scal_zoom2(keycode, fractol);
	else if (keycode == 83 || keycode == 84)
		ft_iso(keycode, fractol);*/
	return (0);
}

int		get_hook(t_fractol *fractol)
{
	/* draw_new(fractol);*/
	return (0);
}

/* void	ft_scal_zoom2(int keycode, t_fdf *fdf)
{
	if (keycode == 125)
	{
		if (fdf->scaly <= 0)
			fdf->scaly = 0;
		else
			fdf->scaly -= 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
	else if (keycode == 126)
	{
		if (fdf->scaly >= HEIGHTH)
			fdf->scaly = HEIGHTH;
		else
			fdf->scaly += 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
}

void	ft_scal_zoom1(int keycode, t_fdf *fdf)
{
	if (keycode == 124)
	{
		if (fdf->scalx <= 0)
			fdf->scalx = 0;
		else
			fdf->scalx -= 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
	else if (keycode == 123)
	{
		if (fdf->scalx >= WIDTH)
			fdf->scalx = WIDTH;
		else
			fdf->scalx += 50;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
}

void	ft_iso(int keycode, t_fdf *fdf)
{
	if (keycode == 83)
	{
		fdf->flag_iso = 0;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
	else if (keycode == 84)
	{
		fdf->flag_iso = 1;
		mlx_clear_window(fdf->ptr, fdf->win);
		draw_new(fdf);
	}
}*/