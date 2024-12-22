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



