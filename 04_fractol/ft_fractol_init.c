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

void	chose_render(t_data *data, t_fractal *fractal)
{
	if (fractal->julia == true)
		draw_julia(fractal, data, fractal->real, fractal->imag);
	else
		draw_mandelbrot(fractal, data);
}

void	zoom(t_fractal *fractal, double factor, bool check, t_data *data)
{
	if (check == false)
		fractal->zoom *= factor;
	if (check == true)
		fractal->zoom /= factor;
	chose_render(data, fractal);
}

void	move(t_fractal *fractal,double factor ,bool  up_or_down, t_data *data)
{
	if (up_or_down == true)
	{
		fractal->shift_y += factor;
	}
	if (up_or_down == false)
	{
		fractal->shift_y -= factor;
	}
	chose_render(data, fractal);
}


void	move_slide(t_fractal *fractal,double factor ,bool  up_or_down, t_data *data)
{
	if (up_or_down == true)
	{
		fractal->shift_x += factor;
	}
	if (up_or_down == false)
	{
		fractal->shift_x -= factor;
	}
	chose_render(data, fractal);
}

void	swift_color(t_fractal *fractal,  t_data *data)
{
	static int i = 0;

	if (i == 0)
	{
		fractal->get_smooth_color = get_smooth_color_limit;
		i++;
	}
	else if (i == 1)
	{
		fractal->get_smooth_color = get_smooth_color_basic;
		i++;
	}
	else if (i == 2)
	{
		fractal->get_smooth_color = get_smooth_color_pow;
		i++;
	}
	else if (i == 3)
	{
		fractal->get_smooth_color = get_smooth_color;
		i = 0;
	}
	chose_render(data, fractal);
}





