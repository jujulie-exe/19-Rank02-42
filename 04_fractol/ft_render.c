/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:39:06 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 18:59:40 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
double map(double value, double from_min, double from_max, double to_min, double to_max) 
{
	return (value - from_min) / (from_max - from_min) * (to_max - to_min) + to_min;
}

void calulate_complex_coords(int x, int y, t_data *data, double aspect_ratio)
{
    data->c_re = map(x, 0, WIDTH, data->fractal->min_re, data->fractal->max_re);
    data->c_im = map(y, 0, HEIGHT, data->fractal->min_im, data->fractal->max_im);
    data->c_re = (data->c_re - data->fractal->shift_x) * data->fractal->zoom + data->fractal->shift_x;
    data->c_im = (data->c_im - data->fractal->shift_y) * data->fractal->zoom + data->fractal->shift_y;
    if (aspect_ratio > 1.0)
        data->c_im /= aspect_ratio;
    else if (aspect_ratio < 1.0)
        data->c_re *= aspect_ratio;
}

void	draw_pixel(t_data *data, int x, int y)
{
	double z_re;
	double z_im;
	int color;
	z_re = 0;
	z_im = 0;
	int iter = mandelbrot(data->c_re, data->c_im, &z_re, &z_im);
	color = data->fractal->get_smooth_color(iter, z_re, z_im);
 	my_mlx_pixel_put(data, x, y, color);	
}
void	draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;
	double	aspect_ratio;

	aspect_ratio = (double) WIDTH / (double)HEIGHT;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calulate_complex_coords(x, y, data, aspect_ratio);
			draw_pixel(data, x, y);
			x++;
		}
		y++;
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

void	draw_julia(t_data  *data)
{
	int	x;
	int	y;
	int	color;
	int	iter;
	double	z_re;
	double	z_im;
	double	aspect_ratio;

	aspect_ratio = (double) WIDTH / (double) HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			calulate_complex_coords(x, y, data, aspect_ratio);
			iter = julia(z_re, z_im, data->c_re, data->c_im);
			color = get_smooth_color_julia(iter, MAX_ITER);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		y++;
	}

}

