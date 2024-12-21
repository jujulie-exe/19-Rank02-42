/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:21:01 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 18:37:14 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        char    *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int mandelbrot(double c_re, double c_im) {
    double z_re = 0;
    double z_im = 0;
    int i = 0;

    while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER) {
        double temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = temp;
        i++;
    }
    return i;
}

int	key_hook(int keycode, t_data *data, t_fractal *fractal)
{
	int i;
	i = check_key(fractal, keycode, data);

	return (i);
}

void	init_fra(t_fractal *fractal)
{

	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
}


int	main() 
{
    t_data data;
    t_fractal fractal;

    init_fra(&fractal);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    	draw_mandelbrot(&fractal, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, (void *)key_hook, &data);


    mlx_loop(data.mlx);
    return 0;
}
