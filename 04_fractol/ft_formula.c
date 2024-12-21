/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formula.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:42:53 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 19:03:43 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(double c_re, double c_im) 
{
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

int	julia(double z_re, double z_im, double c_re, double c_im)
{
	int	i;
	double temp;

	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER)
	{
		temp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = temp;
		i++;
	}
	return (i);
}
