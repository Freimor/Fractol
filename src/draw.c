/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:13:49 by sskinner          #+#    #+#             */
/*   Updated: 2019/08/01 18:21:09 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(float left, float top, float xside, float yside, void *ptr, void *win) 
{
	t_fractol fractol;
    int x, y, i, j;
    int count;
  
    // setting up the xscale and yscale 
    fractol.xscale = xside / XMAX; 
    fractol.yscale = yside / YMAX; 
    fractol.ptr = ptr;
    fractol.win = win;
    // calling rectangle function 
    // where required image will be seen 

  
    // scanning every point in that rectangular area. 
    // Each point represents a Complex number (x + yi). 
    // Iterate that complex number 
    for (y = 1; y <= YMAX - 1; y++) { 
        for (x = 1; x <= XMAX - 1; x++) 
        { 
            // c_real 
            fractol.cx = x * fractol.xscale + left; 
  
            // c_imaginary 
            fractol.cy = y * fractol.yscale + top; 
  
            // z_real 
            fractol.zx = 0; 
  
            // z_imaginary 
            fractol.zy = 0; 
            count = 0; 
  
            // Calculate whether c(c_real + c_imaginary) belongs 
            // to the Mandelbrot set or not and draw a pixel 
            // at coordinates (x, y) accordingly 
            // If you reach the Maximum number of iterations 
            // and If the distance from the origin is 
            // greater than 2 exit the loop 
            while ((fractol.zx * fractol.zx + fractol.zy * fractol.zy < 4) && (count < MAX_COUNT)) 
            { 
                // Calculate Mandelbrot function 
                // z = z*z + c where z is a complex number 
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real 
                fractol.tempx = fractol.zx * fractol.zx - fractol.zy * fractol.zy + fractol.cx; 
  
                // 2*z_real*z_imaginary + c_imaginary 
                fractol.zy = 2 * fractol.zx * fractol.zy + fractol.cy; 
  
                // Updating z_real = tempx 
                fractol.zx = fractol.tempx; 
  
                // Increment count 
                count = count + 1; 
            } 
  
            // To display the created fractal 
			mlx_pixel_put(fractol.ptr, fractol.win, fractol.zx + 50, fractol.zy + 50, RED);
        } 
    } 
} 