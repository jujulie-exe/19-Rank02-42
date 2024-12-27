/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smoth_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:42:15 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/27 14:42:19 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_smooth_color_julia(int iter, int max_iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iter / (double)max_iter;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	get_smooth_color_pow(int iter, double z_re, double z_im)
{
	t_gt	pw;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	pw.magnitude = sqrt(z_re * z_re + z_im * z_im);
	pw.smooth_iter = iter + 1 - log2(log2(pw.magnitude));
	pw.t = pw.smooth_iter / MAX_ITER;
	pw.t = pow(pw.t, 0.8);
	r = (int)(9 * (1 - pw.t) * pw.t * 255);
	g = (int)(15 * (1 - pw.t) * pw.t * pw.t * 255);
	b = (int)(8.5 * (1 - pw.t) * pw.t * pw.t * pw.t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_smooth_color(int iter, double z_re, double z_im)
{
	t_gt	sq;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	sq.magnitude = sqrt(z_re * z_re + z_im * z_im);
	sq.smooth_iter = iter + 1 - log2(log2(sq.magnitude));
	sq.t = sq.smooth_iter / MAX_ITER;
	r = (int)(128 + 127 * sin(5.0 * M_PI * sq.t));
	g = (int)(128 + 127 * sin(5.0 * M_PI * sq.t + 2.0));
	b = (int)(128 + 127 * sin(5.0 * M_PI * sq.t + 4.0));
	b = (int)(8.5 * (1 - sq.t) * sq.t * sq.t * sq.t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_smooth_color_basic(int iter, double z_re, double z_im)
{
	double	magnitude;
	double	smooth_iter;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	magnitude = sqrt(z_re * z_re + z_im * z_im);
	smooth_iter = iter + 1 - log2(log2(magnitude));
	r = (int)(9 * (1 - smooth_iter / MAX_ITER) * 255);
	g = (int)(15 * (1 - smooth_iter / MAX_ITER) * 255);
	b = (int)(8.5 * (1 - smooth_iter / MAX_ITER) * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_smooth_color_limit(int iter, double z_re, double z_im)
{
	t_gt	lmt;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	lmt.magnitude = sqrt(z_re * z_re + z_im * z_im);
	lmt.smooth_iter = iter + 1 - log2(log2(lmt.magnitude));
	lmt.t = lmt.smooth_iter / MAX_ITER;
	lmt.t = pow(lmt.t, 0.8);
	r = (int)(1 * (1 - lmt.t) * lmt.t * lmt.t * 255);
	g = (int)(2 * (1 - lmt.t) * lmt.t * lmt.t * 255);
	b = (int)(30 * (1 - lmt.t) * lmt.t * lmt.t * 255);
	if (r > 30)
		r = 30;
	if (g > 30)
		g = 30;
	if (b < 30)
		b = 60;
	return ((r << 16) | (g << 8) | b);
}
