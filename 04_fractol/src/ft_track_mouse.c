/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:42:30 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/27 14:42:36 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_target_coordinates(int x, int y,
		t_data *data, t_complex *target)
{
	target->real = ((x - 0) / (double)(WIDTH - 0))
		* (data->fractal->max_re - data->fractal->min_re)
		+ data->fractal->min_re;
	target->real = (target->real - data->fractal->shift_x)
		* data->fractal->zoom
		+ data->fractal->shift_x;
	target->imag = ((y - 0) / (double)(HEIGHT - 0))
		* (data->fractal->max_im - data->fractal->min_im)
		+ data->fractal->min_im;
	target->imag = (target->imag - data->fractal->shift_y)
		* data->fractal->zoom
		+ data->fractal->shift_y;
}

void	update_fractal_and_debounce(t_data *data, t_complex *target)
{
	static int		frame_counter = 0;
	const int		debounce_frame = 45;
	const double	attenuation_factor = 0.001 * pow(0.9, data->fractal->zoom);

	data->fractal->real
		+= (target->real - data->fractal->real)
		* attenuation_factor;
	data->fractal->imag
		+= (target->imag - data->fractal->imag)
		* attenuation_factor;
	frame_counter++;
	if (frame_counter >= debounce_frame)
	{
		draw_julia(data->fractal, data, data->fractal->real,
			data->fractal->imag);
		frame_counter = 0;
	}
}

int	track_mouse(int x, int y, t_data *data)
{
	t_complex	target;

	if (data->fractal->julia == true)
	{
		calculate_target_coordinates(x, y, data, &target);
		update_fractal_and_debounce(data, &target);
	}
	return (0);
}
