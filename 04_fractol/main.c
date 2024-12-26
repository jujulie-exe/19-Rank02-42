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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color ;
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
	fractal->julia = false;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->get_smooth_color = get_smooth_color;
}

void	init_data(t_data *data, t_fractal *fractal)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian);
	data->fractal = fractal;
}

int	exit_err(t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
	{
		free(data->mlx);
		data->mlx = NULL;
	}
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_fractal	fractal;

	init_fra(&fractal);
	init_data(&data, &fractal);
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
			init_julia(&data, argv[2], argv[3]);
		else
			draw_mandelbrot(&fractal, &data);
	}
	else
		ft_message();
	mlx_hook(data.win, 6, (1L << 6), track_mouse, &data);
	mlx_hook(data.win, 4, (1L << 2), mouse_hook, &data);
	mlx_hook(data.win, 2, (1L << 0), key_hook, &data);
	mlx_hook(data.win, 17, (0), exit_err, &data);
	mlx_loop(data.mlx);
	return (0);
}
