/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_service.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:19:09 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/31 16:57:45 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_mac.h"

int		key_hook_press(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == MAIN_PAD_ESC)
	{
		fractol_memfree(fractol);
		exit(0);
	}
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
			|| keycode == ARROW_DOWN || keycode == ARROW_UP)
		movement(keycode, fractol);
	else if (keycode == NUM_PAD_MINUS || keycode == NUM_PAD_PLUS)
		zoom(keycode, fractol);
	else if (keycode == MAIN_PAD_1 || keycode == MAIN_PAD_2 || keycode == 20)
		color_change(keycode, fractol);
	else if (keycode == MAIN_PAD_MINUS || keycode == MAIN_PAD_PLUS
	|| keycode == MAIN_PAD_C_BRAC_L || keycode == MAIN_PAD_C_BRAC_R
	|| keycode == MAIN_PAD_D)
		mods_one(keycode, fractol);
	else if (keycode == MAIN_PAD_I)
		hide_help(fractol);
	else if (keycode == MAIN_PAD_Z || keycode == MAIN_PAD_X
	|| keycode == MAIN_PAD_COMMA || keycode == MAIN_PAD_DOT)
		mods_two(keycode, fractol);
	return (0);
}

int		mouse_hook(int keycode, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_SCROLL_UP)
		zoom(keycode, fractol);
	return (0);
}

void	fractol_memfree(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	free(fractol);
	return ;
}
