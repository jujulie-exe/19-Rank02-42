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
		fractal->zoom *= factor;
	if (check == true)
		fractal->zoom /= factor;
	draw_mandelbrot(fractal, data);
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

