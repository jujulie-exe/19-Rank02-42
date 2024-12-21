/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:02:38 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 18:30:19 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fractal, double factor, bool check, t_data *data)
{
	if (check == false)
	{
		fractal->min_re *= factor;
		fractal->max_re *= factor;
		fractal->min_im *= factor;
		fractal->max_im *= factor;
	}
	if (check == true)
	{
		
		fractal->min_re /= factor;
		fractal->max_re /= factor;
		fractal->min_im /= factor;
		fractal->max_im /= factor;
	}
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	draw_mandelbrot(fractal, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}


int	check_key(t_fractal *fractal, int keycode, t_data *data)
{
	if (keycode == 119)
	{
		zoom(fractal, 0.9, false, data);
		return (1);
	}
	else if (keycode == 114)
	{
		zoom(fractal, 0.9, true, data);
		return (1);
	}
	else if (keycode == 114)
		init_fra(fractal);
	return (0);
}

