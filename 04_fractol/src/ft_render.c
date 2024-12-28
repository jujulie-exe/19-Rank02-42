/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:39:06 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/28 14:40:16 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calulate_complex_coords(t_info *info, t_fractal *fractal,
		double *c_re, double *c_im)
{
	*c_re = ((info->x - 0) / (double)(WIDTH - 0))
		* (fractal->max_re - fractal->min_re) + fractal->min_re;
	*c_im = ((info->y - 0) / (double)(HEIGHT - 0))
		* (fractal->max_im - fractal->min_im) + fractal->min_im;
	*c_re = (*c_re - fractal->shift_x) * fractal->zoom + fractal->shift_x;
	*c_im = (*c_im - fractal->shift_y) * fractal->zoom + fractal->shift_y;
	if (info->aspect_ratio > 1.0)
		*c_im /= info->aspect_ratio;
	else if (info->aspect_ratio < 1.0)
		*c_re *= info->aspect_ratio;
}

void	draw_pixel(t_data *data, t_info *info, double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	int		color;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = mandelbrot(c_re, c_im, &z_re, &z_im);
	color = data->fractal->get_smooth_color(iter, z_re, z_im);
	my_mlx_pixel_put(data, info, color);
}

void	draw_mandelbrot(t_fractal *fractal, t_data *data)
{
	t_info	info;
	double	c_re;
	double	c_im;

	info.aspect_ratio = (double) WIDTH / (double)HEIGHT;
	info.y = 0;
	while (info.y < HEIGHT)
	{
		info.x = 0;
		while (info.x < WIDTH)
		{
			calulate_complex_coords(&info, fractal, &c_re, &c_im);
			draw_pixel(data, &info, c_re, c_im);
			info.x++;
		}
		info.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	draw_julia(t_fractal *fractal, t_data *data, double c_re, double c_im)
{
	t_info	info;
	int		color;
	int		iter;
	double	z_re;
	double	z_im;

	info.aspect_ratio = (double) WIDTH / (double) HEIGHT;
	info.y = 0;
	while (info.y < HEIGHT)
	{
		info.x = 0;
		while (info.x < WIDTH)
		{
			calulate_complex_coords(&info, fractal, &z_re, &z_im);
			iter = julia(z_re, z_im, c_re, c_im);
			color = get_smooth_color_julia(iter, MAX_ITER);
			my_mlx_pixel_put(data, &info, color);
			info.x++;
		}
		info.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
