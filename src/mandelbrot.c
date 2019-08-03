/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:22:50 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/03 17:46:23 by sskinner         ###   ########.fr       */
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
void	fractol_test(t_fractol *fractol)
{
	float zi, zr, ci, cr, tmp;
	int i, j, k, m;
	
	i = -(XMAX / 2);
	while (i < XMAX / 2)
	{                      //  проходим по всем пикселям оси х
		ci = (((float)i + XC) / (float)(ZOOM)); //160.0
		j = -(YMAX / 2);                    //  присваеваем мнимой части с - i/160
		while (j < YMAX / 2)  
		{                 //  проходим по всем пикселям оси y6
			cr = (((float)j + YC) / (float)(ZOOM));             //  присваеваем  ещественной части с - j/120
			zi = zr = 0.0;
			k = 0;                       //  присваеваем вещественной и мнимой части z - 0
			while (k < DEPTH)
			{         //  вычисляем множество Мандельброта 
				tmp = zr*zr - zi*zi;
				zi = 2*zr*zi + ci;
				zr = tmp + cr;
				if (zr*zr + zi*zi > 1.0E16)        //  если |z| слишком велико, то
					break;                           //  выход из цикла
				k++;
			}
			if (k < DEPTH)
			{                     //  |z| - велико
				m = k%8 + 1;                       //  - это внешняя точка
				putpixel(fractol, i + XMAX / 2, j + YMAX / 2, color(m*4 + 231, 76, 60));     //	 красного
			}
			else
				putpixel(fractol, i + XMAX / 2, j + YMAX / 2, color(0,0,0));      // внутренняя точка и закрашиваем её в чёрный цвет
			j++;
		}
		i++;
	}
}