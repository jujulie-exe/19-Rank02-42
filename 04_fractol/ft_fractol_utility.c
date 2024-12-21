/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:39:06 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 17:00:47 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calulate_complex_coords(int x, int y, t_fractal *fractal, double *c_re, double *c_im, double aspect_ratio)
{
	*c_re = fractal->min_re + (x / (WIDTH - 1.0)) * (fractal->max_re - fractal->min_re);
	*c_im = fractal->min_im + (y / (HEIGHT - 1.0)) * (fractal->max_im - fractal->min_im);
	if (aspect_ratio > 1.0)
		*c_im /= aspect_ratio;
	else if (aspect_ratio < 1)
		*c_re *= aspect_ratio;
}
void	draw_pixel(t_data *data, int x, int y, double c_re, double c_im)
{
	int iter = mandelbrot(c_re, c_im); // fare una funzione per tutti i tipi di frate
	int color;

	if (iter == MAX_ITER)
		color = 0x000000;
	else
		color = (iter * 0xFFFFFF) / MAX_ITER;
 	my_mlx_pixel_put(data, x, y, color);	
}
void	draw_mandelbrot(t_fractal *fractal, t_data *data)
{
	int	x;
	int	y;
	double	aspect_ratio;
	double	c_re;
	double	c_im;

	aspect_ratio = (double) WIDTH / HEIGHT;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calulate_complex_coords(x, y, fractal, &c_re, &c_im, aspect_ratio);
			draw_pixel(data, x, y, c_re, c_im);
			x++;
		}
		y++;
	}
}

