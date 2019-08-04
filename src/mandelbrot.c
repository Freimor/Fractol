/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   fractol->c_reated: 2019/08/02 17:22:50 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/04 16:20:49 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//||WORKS||WORKS||WORKS||WORKS||WORKS||WORKS||WORKS||WORKS||WORKS||WORKS//
#include <fractol.h>
 
//установка точки на экран
void putpixel (t_fractol *fractol, int x, int y, int color)
{
	mlx_pixel_put(fractol->ptr, fractol->win, x, y, color);
	return;
}
//функция установки цвета
int color(int r, int g,int b)
{
	return ((r << 16) | (g << 8) | b);
}
void	mandelbrot(t_fractol *mand)
{
	float	temp;
	int		i;
	int		j;
	int		k;
	int		m;
	
	i = -(XMAX / 2);
	while (i < XMAX / 2)
	{
		mand->c_i = (((float)i + mand->move_x) / mand->zoom); //160.0
		j = -(YMAX / 2);                    //imaginary  присваеваем мнимой части с - i/160
		while (j < YMAX / 2)  
		{                 //  проходим по всем пикселям оси y6
			mand->c_r = (((float)j + mand->move_y) / mand->zoom);             //real  присваеваем  вещественной части с - j/120
			mand->z_i = mand->z_r = 0.0;
			k = 0;                       //  присваеваем вещественной и мнимой части z - 0
			while (k < ITERATION )
			{         //  вычисляем множество Мандельброта 
				temp = mand->z_r * mand->z_r - mand->z_i * mand->z_i;
				mand->z_i = 2 * mand->z_r * mand->z_i + mand->c_i;
				mand->z_r = temp + mand->c_r;
				if (mand->z_r*mand->z_r + mand->z_i * mand->z_i > 1.0E16)        //  если |z| слишком велико, то
					break;                           //  выход из цикла
				k++;
			}
			if (k < ITERATION)
			{                     //  |z| - велико
				m = (k%8 + 1) * 4;                       //  - это внешняя точка
				putpixel(mand, i + XMAX / 2, j + YMAX / 2, color(m + 231, 76, 60));     //	 красного
			}
			else
				putpixel(mand, i + XMAX / 2, j + YMAX / 2, color(0,0,0));      // внутренняя точка и закрашиваем её в чёрный цвет
			j++;
		}
		i++;
	}
}
