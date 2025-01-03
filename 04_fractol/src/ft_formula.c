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

int	mandelbrot(double c_re, double c_im, double *z_re_out, double *z_im_out)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER)
	{
		temp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = temp;
		i++;
	}
	*z_re_out = z_re;
	*z_im_out = z_im;
	return (i);
}

int	julia(double z_re, double z_im, double c_re, double c_im)
{
	double	temp;
	int		i;

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
