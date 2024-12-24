/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:21:01 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 19:10:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void    my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        char    *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}



void	init_fra(t_fractal *fractal)
{

	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->zoom = 1.0;
	fractal->real = -0.8;
	fractal->imag = 0.2;
	fractal->julia = true;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->get_smooth_color = get_smooth_color; 
}

void	init_data(t_data *data, t_fractal *fractal)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->fractal = fractal;

}


int	main() 
{
	t_data data;
	t_fractal fractal;
	
	init_fra(&fractal);
	init_data(&data, &fractal);
	if (fractal.julia == true)
		draw_julia(&fractal, &data, fractal.real, fractal.imag);
	else
		draw_mandelbrot(&fractal, &data);
	mlx_hook(data.win, 6, (1L<<6), track_mouse,&data);
	mlx_hook(data.win, 4, (1L<<2), mouse_hook,&data);
	mlx_hook(data.win, 2, (1L<<0), key_hook,&data);
	//mlx_hook(data.win, 17, (1L<<2), mouse_hook,&data);
	mlx_loop(data.mlx);
	return 0;
}
